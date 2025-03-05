#ifndef SELECTVIM_H
#define SELECTVIM_H

#include <QWidget>
#include <QSqlTableModel>
namespace Ui {
class SelectVim;
}

class SelectVim : public QWidget
{
    Q_OBJECT

public:
    explicit SelectVim(QWidget *parent = nullptr);
    ~SelectVim();

private slots:
    void on_selectBt_clicked();

private:
    Ui::SelectVim *ui;
    QSqlTableModel* model;
};

#endif // SELECTVIM_H
