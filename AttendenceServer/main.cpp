#include "attendencevim.h"
#include "selectvim.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <registervim.h>
#include <ui_selectvim.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<cv::Mat>("cv::Mat&");
    qRegisterMetaType<cv::Mat>("cv::Mat");
    qRegisterMetaType<int64_t>("int64_t");
//    RegisterVim ww;
//    ww.show();
    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据名称
    db.setDatabaseName("server.db");
    //打开数据库
    if(!db.open()){
        qDebug()<<db.lastError().text();
        return -1;

    }
    //创建员工信息表
    /*QString createsql = "create table if not exists employee(employeeID integer primary key autoincrement, name varchar(256), sex varchar(32),"
                        "birthday text, address text, phone text, faceID integer unique, headfile text)";
    QString createsql = "create table if not exists employee(employeeID integer primary key autoincrement,name varchar(256), sex varchar(32),"
                            "birthday text, address text, phone text, faceID integer unique, headfile text)";*/
    QString createsql = "create table if not exists employee(employeeID integer primary key autoincrement,name varchar(256), sex varchar(32),"
                            "birthday text, address text, phone text, faceID integer unique, headfile text)";

    QSqlQuery query;
    if(!query.exec(createsql))
    {
        qDebug()<<query.lastError().text();
        return -1;
    }
    //创建考勤表格
    /*createsql = "create table if not exists attendence(attendence integer primay key autoincrement, employeeID integer,"
                "attendenceTime Timestamp NOT NULL DEFAULT(datatime('now','localtime')))";*/
    createsql = "create table if not exists attendance(attendaceID integer primary key autoincrement, employeeID integer,"
                    "attendaceTime TimeStamp NOT NULL DEFAULT(datetime('now','localtime')))";
    if(!query.exec(createsql)){
        qDebug()<<query.lastError().text();
        return -1;
    }
    AttendenceVim w;
//    AttendenceVim *ww;
//    ww = &w;
//    ww->resize(1200, 800);
    w.show();
//    SelectVim sw;
//    sw.show();
    return a.exec();
}
