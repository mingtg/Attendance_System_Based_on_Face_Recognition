#ifndef FACEATTENDENCE_H
#define FACEATTENDENCE_H

#include <QMainWindow>
#include <opencv.hpp>
#include <QTcpSocket>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
using namespace std;
using namespace cv;
QT_BEGIN_NAMESPACE
namespace Ui { class FaceAttendence; }
QT_END_NAMESPACE

class FaceAttendence : public QMainWindow
{
    Q_OBJECT

public:
    FaceAttendence(QWidget *parent = nullptr);
    ~FaceAttendence();
    //定时器事件
    void timerEvent(QTimerEvent *e);
private slots:
    void timer_connect();//定时启动去连接服务器
    void stop_connect();//断开连接
    void start_connect();//开始连接
    void recv_data();
private:
    Ui::FaceAttendence *ui;

    //摄像头
    VideoCapture cap;
    //haar--级联分类器
    cv::CascadeClassifier cascade;

    //创建网络套接字，定时器
    QTcpSocket msocket;
    QTimer mtimer;

    //标志是否是同一个人脸进入到识别区域
    int flag;
    //保存人脸的数据
    cv::Mat faceMat;
};
#endif // FACEATTENDENCE_H
