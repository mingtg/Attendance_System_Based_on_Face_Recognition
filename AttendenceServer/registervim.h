#ifndef REGISTERVIM_H
#define REGISTERVIM_H

#include <QWidget>
#include <opencv.hpp>
namespace Ui {
class RegisterVim;
}

class RegisterVim : public QWidget
{
    Q_OBJECT
public:
    explicit RegisterVim(QWidget *parent = nullptr);
    ~RegisterVim();
    void timerEvent(QTimerEvent *e);
signals:

private slots:
    void on_resetBt_clicked();

    void on_addpicBt_clicked();

    void on_registerBt_clicked();

    void on_cameraBt_clicked();

    void on_videoswitchBt_clicked();


private:
    Ui::RegisterVim *ui;
    int timerid;
    cv::VideoCapture cap;
    cv::Mat image;
};

#endif // REGISTERVIM_H
