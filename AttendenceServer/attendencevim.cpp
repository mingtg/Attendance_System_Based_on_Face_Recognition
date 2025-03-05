#include "attendencevim.h"
#include "ui_attendencevim.h"
#include <opencv.hpp>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDateTime>
#include <QThread>
#include <QSqlQuery>
#include <QSqlError>
AttendenceVim::AttendenceVim(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AttendenceVim)
{
    ui->setupUi(this);
    //qtcpServer 当有客户端连接会发送newconnection
    connect(&mServer, &QTcpServer::newConnection, this, &AttendenceVim::accept_client);
    mServer.listen(QHostAddress::Any, 6000);//监听，启动服务器
    bsize = 0;

    //给sql模型绑定表格
    model.setTable("employee");

    //创建一个线程
    QThread *thread = new QThread();
    //把QFaceObject对象移动到thread线程中执行
    fobj.moveToThread(thread);
    //启动线程
    thread->start();
    //函数不能直接调用，要通过信号触发调用
    connect(this, &AttendenceVim::query, &fobj, &QFaceObject::face_query);
    //关联QFaceObject
    connect(&fobj,&QFaceObject::send_faceid, this, &AttendenceVim::recv_faceid);
}

AttendenceVim::~AttendenceVim()
{
    delete ui;
}
//接受客户端连接
void AttendenceVim::accept_client(){
    //获取与客户端通信的套接字
    msocket = mServer.nextPendingConnection();

    //当客户端有数据到达会发送readyRead信号
    connect(msocket, &QTcpSocket::readyRead, this, &AttendenceVim::read_data);
}
//读取客户端发来的数据
void AttendenceVim::read_data(){
    QDataStream stream(msocket);//把套接字绑定到数据流
    stream.setVersion(QDataStream::Qt_5_14);
    //读取文件大小
    if(bsize == 0){
        if(msocket->bytesAvailable() < (qint64)sizeof (bsize)) return;
        //采集数据的长度
        stream>>bsize;
    }
    //判断文件是否发送完毕
    if(msocket->bytesAvailable() < bsize){//说明数据还没有发送完成，返回继续等待
        return;
    }
    QByteArray data;
    stream>>data;
    bsize = 0;
    if(data.size() == 0){//没有读取到数据
        return;
    }
    //显示图片
    QPixmap mmp;
    mmp.loadFromData(data, "jpg");
    mmp = mmp.scaled(ui->picLb->size());
    ui->picLb->setPixmap(mmp);
    this->adjustSize();
    //识别人脸
    cv::Mat faceImage;
    std::vector<uchar> decode;
    decode.resize(data.size());
    memcpy(decode.data(), data.data(), data.size());
    //将字节流数据转换成faceimage
    faceImage = cv::imdecode(decode, cv::IMREAD_COLOR);
    //int faceid = fobj.face_query(faceImage);//消耗资源较多
    emit query(faceImage);

}
void AttendenceVim::recv_faceid(int64_t faceid)
{
    //qDebug()<<faceid;

    //从数据库中查询faceid对应的个人信息
    //给模型设置过滤器
    qDebug()<<"识别到的人脸id:"<<faceid;
    if(faceid < 0)
    {
        QString sdmsg = QString("{\"employeeID\":\" \",\"name\":\"\",\"department\":\"\",\"time\":\"\"}");
        msocket->write(sdmsg.toUtf8());//把打包好的数据发送给客户端
        return;
    }
    model.setFilter(QString("faceID=%1").arg(faceid));
    //查询
    model.select();
    //判断是否查询到数据
    if(model.rowCount() == 1)
    {
       //工号，姓名，部门，时间
       //{employeeID:%1,name:%2,department:软件,time:%3}
       QSqlRecord record = model.record(0);
       QString sdmsg = QString("{\"employeeID\":\"%1\",\"name\":\"%2\",\"department\":\"软件\",\"time\":\"%3\"}")
               .arg(record.value("employeeID").toString()).arg(record.value("name").toString())
               .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));


       //把数据写入数据库--考勤表
       QString insertSql = QString("insert into attendance(employeeID) values('%1')").arg(record.value("employeeID").toString());
       QSqlQuery query;
       if(!query.exec(insertSql))
       {
           QString sdmsg = QString("{\"employeeID\":\" \",\"name\":\"\",\"department\":\"\",\"time\":\"\"}");
           msocket->write(sdmsg.toUtf8());//把打包好的数据发送给客户端
           qDebug()<<query.lastError().text();
           return;
        }else
       {
           msocket->write(sdmsg.toUtf8());//把打包好的数据发送给客户端
       }
    }
}
