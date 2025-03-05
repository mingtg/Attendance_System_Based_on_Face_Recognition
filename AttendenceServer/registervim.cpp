//#include "registervim.h"
//#include "ui_registervim.h"
//#include <QFileDialog>
//#include <qfaceobject.h>
//#include <QSqlTableModel>
//#include <QSqlRecord>
//#include <QMessageBox>
//#include <QDebug>
//RegisterVim::RegisterVim(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::RegisterVim)
//{
//    ui->setupUi(this);
//}

//RegisterVim::~RegisterVim()
//{
//    delete ui;
//}

//void RegisterVim::timerEvent(QTimerEvent *e)
//{
//    //获取摄像头数据并且显示在界面上

//    if(cap.isOpened())
//    {
//        cap>>image;
//        if(image.data == nullptr) return;
//    }
//    //Mat----->>>QImage;
//    cv::Mat rgbImage;
//    cv::cvtColor(image, rgbImage, cv::COLOR_BGR2RGB);
//    QImage qImg(rgbImage.data, image.cols, rgbImage.rows, rgbImage.step1(), QImage::Format_RGB888);
//    //在qt界面上显示
//    QPixmap mmp = QPixmap::fromImage(qImg);
//    mmp = mmp.scaledToWidth(ui->headpicLb->width());
//    ui->headpicLb->setPixmap(mmp);
////    RegisterVim *ww = this;
////    ww->resize(1200, 800);
//}

//void RegisterVim::on_resetBt_clicked()
//{
//    //清空数据
//    ui->nameEdit->clear();
//    ui->birthdayEdit->setDate(QDate::currentDate());
//    ui->addressEdit->clear();
//    ui->phoneEdit->clear();
//    ui->picFileEdit->clear();
//}

//void RegisterVim::on_addpicBt_clicked()
//{
//    //通过文件对话框 选中图片路径
//    QString filepath = QFileDialog::getOpenFileName(this);
//    ui->picFileEdit->setText(filepath);

//    //显示图片
//    QPixmap mmp(filepath);
//    mmp = mmp.scaledToWidth(ui->headpicLb->width());
//    mmp = mmp.scaledToHeight(ui->headpicLb->height());
//    ui->headpicLb->setPixmap(mmp);
//}

//void RegisterVim::on_registerBt_clicked()
//{
//    //检查图片文件是否存在
//    QString picFilePath = ui->picFileEdit->text();
//       if (!QFile::exists(picFilePath)) {
//           QMessageBox::warning(this, "文件错误", "选择的图片文件不存在！");
//           return;
//       }

//    //1.通过照片，结合faceObject模块得到faceID
//    QFaceObject faceobj;
//    cv::Mat image = cv::imread(ui->picFileEdit->text().toUtf8().data());
//    if (image.empty()) {
//            QMessageBox::warning(this, "图像错误", "无法读取图片文件，请检查文件路径或文件完整性！");
//            return;
//        }

//    int faceID = faceobj.face_register(image);
//    qDebug()<<faceID;
//    if (faceID < 0) {
//           QMessageBox::critical(this, "错误", "人脸注册失败");
//           return;
//       }
//    //把头像保存到一个固定路径下
//        QString headfile = QString("./data/%1.jpg").arg(QString(ui->nameEdit->text().toUtf8().toBase64()));
//        cv::imwrite(headfile.toUtf8().data(), image);
//        QDir dataDir("./data");
//           if (!dataDir.exists() && !dataDir.mkpath(".")) {
//               QMessageBox::warning(this, "错误", "无法创建数据目录");
//               return;
//           }

//       if (!cv::imwrite(headfile.toUtf8().data(), image)) {
//           QMessageBox::warning(this, "文件错误", "无法保存图片文件，请检查文件路径或文件权限！");
//           return;
//       }
//      // 检查文件是否保存成功
//      if (!QFile::exists(headfile)) {
//          QMessageBox::warning(this, "文件错误", "保存的图片文件不存在，请检查文件路径或文件权限！");
//          return;
//      }
////    cv::imwrite(headfile.toUtf8().data(),image);
//    //2.把个人信息存储到数据库empolyee
//    QSqlTableModel model;
//    model.setTable("employee");//设置表名
//    QSqlRecord record = model.record();
//    //设置数据
//    record.setValue("name",ui->nameEdit->text());
//    record.setValue("sex",ui->mrb->isChecked()?"男":"女");
//    record.setValue("birthday",ui->birthdayEdit->text());
//    record.setValue("address",ui->addressEdit->text());
//    record.setValue("phone",ui->phoneEdit->text());
//    record.setValue("faceID",faceID);
//    //头像路径
//    record.setValue("headfile",headfile);
//    //把记录插入到数据库表格中
//    bool ret = model.insertRecord(0,record);
//    //3.提示注册成功
//    if(ret){
//        QMessageBox::information(this,"注册提示","注册成功");
//    }else{
//        QMessageBox::information(this,"注册提示","注册失败");
//    }
//}


//void RegisterVim::on_videoswitchBt_clicked()
//{
//    if(ui->videoswitchBt->text() =="打开摄像头"){
//        //打开摄像头
//        if(cap.open(0)){
//            ui->videoswitchBt->setText("关闭摄像头");
//            //启动定时器事件
//            timerid = startTimer(100);
//        }
//    }else
//    {
//        killTimer(timerid);//关闭定时器事件
//        ui->videoswitchBt->setText("打开摄像头");
//        //关闭摄像头
//        cap.release();
//    }
//}

//void RegisterVim::on_cameraBt_clicked()
//{
//    //保存数据
//    //把头像保存到一个固定路径下
//    QString headfile = QString("./data/%1.jpg").arg(QString(ui->nameEdit->text().toUtf8().toBase64()));
//    ui->picFileEdit->setText(headfile);
//    cv::imwrite(headfile.toUtf8().data(), image);
//    if (ui->picFileEdit->text().isEmpty()) {
//        QMessageBox::warning(this, "文件错误", "图片文件路径不存在！");
//        return;
//    }

//    killTimer(timerid);//关闭定时器事件
//    ui->videoswitchBt->setText("打开摄像头");
//    //关闭摄像头
//    cap.release();
//}
#include "registervim.h"
#include "ui_registervim.h"
#include <QFileDialog>
#include <qfaceobject.h>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>

RegisterVim::RegisterVim(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterVim)
{
    ui->setupUi(this);
}

RegisterVim::~RegisterVim()
{
    delete ui;
}

void RegisterVim::timerEvent(QTimerEvent *e)
{

    //获取摄像头数据并且显示在界面上
    if(cap.isOpened())
    {
        cap>>image;
        if(image.data == nullptr) return;
    }
    //Mat---》QImage
    cv::Mat rgbImage;
    cv::cvtColor(image,rgbImage,cv::COLOR_BGR2RGB);
    QImage qImg(rgbImage.data, rgbImage.cols, rgbImage.rows,rgbImage.step1(), QImage::Format_RGB888);
    //在qt界面上显示
    QPixmap mmp=QPixmap::fromImage(qImg);
    mmp = mmp.scaledToWidth(ui->headpicLb->width());
    ui->headpicLb->setPixmap(mmp);

}

void RegisterVim::on_resetBt_clicked()
{
    //清空数据
    ui->nameEdit->clear();
    ui->birthdayEdit->setDate(QDate::currentDate());
    ui->addressEdit->clear();
    ui->phoneEdit->clear();
    ui->picFileEdit->clear();
}

void RegisterVim::on_addpicBt_clicked()
{
    //通过文件对话框 选中图片路径
    QString filepath = QFileDialog::getOpenFileName(this);
    ui->picFileEdit->setText(filepath);


    //显示图片
    QPixmap mmp(filepath);
    mmp = mmp.scaledToWidth(ui->headpicLb->width());
    ui->headpicLb->setPixmap(mmp);
}

void RegisterVim::on_registerBt_clicked()
{
    //1.通过照片，结合faceObject模块得到faceID
    QFaceObject  faceobj;
    cv::Mat image = cv::imread(ui->picFileEdit->text().toUtf8().data());
    int faceID = faceobj.face_register(image);
    qDebug()<<faceID;
    //把头像保存到一个固定路径下
    QString headfile = QString("./data/%1.jpg").arg(QString(ui->nameEdit->text().toUtf8().toBase64()));
    cv::imwrite(headfile.toUtf8().data(), image);


    //2.把个人信息存储到数据库employee
    QSqlTableModel model;
    model.setTable("employee");//设置表名
    QSqlRecord record = model.record();
    //设置数据
    record.setValue("name",ui->nameEdit->text());
    record.setValue("sex",ui->mrb->isChecked()?"男":"女");
    record.setValue("birthday", ui->birthdayEdit->text());
    record.setValue("address",ui->addressEdit->text());
    record.setValue("phone",ui->phoneEdit->text());
    record.setValue("faceID", faceID);
    //头像路径
    record.setValue("headfile",headfile);
    //把记录插入到数据库表格中
    bool ret = model.insertRecord(0,record);
    //3.提示注册成功
    if(ret)
    {
        QMessageBox::information(this,"注册提示","注册成功");
        //提交
        model.submitAll();
    }else
    {
        QMessageBox::information(this,"注册提示","注册失败");
    }
}

void RegisterVim::on_videoswitchBt_clicked()
{
    if(ui->videoswitchBt->text() == "打开摄像头")
    {
        //打开摄像头
        if(cap.open(0))
        {
            ui->videoswitchBt->setText("关闭摄像头");
            //启动定时器事件
            timerid = startTimer(100);
        }
    }else
    {

        killTimer(timerid);//关闭定时器事件
        ui->videoswitchBt->setText("打开摄像头");
        //关闭摄像头
        cap.release();
    }
}

void RegisterVim::on_cameraBt_clicked()
{
    //保存数据
    //把头像保存到一个固定路径下
    QString headfile = QString("./data/%1.jpg").arg(QString(ui->nameEdit->text().toUtf8().toBase64()));
    headfile.replace("/", "_");  // 替换可能导致路径问题的字符
    ui->picFileEdit->setText(headfile);
    if (image.empty()) {
        QMessageBox::warning(this, "错误", "未捕获到有效图像");
        return;
    }
    cv::imwrite(headfile.toUtf8().data(), image);
    killTimer(timerid);//关闭定时器事件
    ui->videoswitchBt->setText("打开摄像头");
    //关闭摄像头
    cap.release();
}
