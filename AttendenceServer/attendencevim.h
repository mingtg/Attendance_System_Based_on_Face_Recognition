#ifndef ATTENDENCEVIM_H
#define ATTENDENCEVIM_H
#include "qfaceobject.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QSqlTableModel>
#include <QSqlRecord>
QT_BEGIN_NAMESPACE
namespace Ui { class AttendenceVim; }
QT_END_NAMESPACE

class AttendenceVim : public QMainWindow
{
    Q_OBJECT

public:
    AttendenceVim(QWidget *parent = nullptr);
    ~AttendenceVim();
signals:
    void query(cv::Mat& image);
protected slots:
    void accept_client();
    void read_data();
private slots:
    void recv_faceid(int64_t faceid);
private:
    Ui::AttendenceVim *ui;
    QTcpServer mServer;
    QTcpSocket *msocket;
    quint64 bsize;
    QFaceObject fobj;
    QSqlTableModel model;

};
#endif // ATTENDENCEVIM_H
