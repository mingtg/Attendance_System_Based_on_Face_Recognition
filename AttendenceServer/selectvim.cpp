#include "selectvim.h"
#include "ui_selectvim.h"

SelectVim::SelectVim(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectVim)
{
    ui->setupUi(this);
    model = new QSqlTableModel();
}

SelectVim::~SelectVim()
{
    delete ui;
}

void SelectVim::on_selectBt_clicked()
{
    if(ui->empRb->isChecked())
    {
        model->setTable("employee");//设置员工表格
    }
    if(ui->attRb->isChecked())
    {
        model->setTable("attendence");
    }
    //设置过滤器
    //model->setFilter("name='张三'");
    //查询
    model->select();

    ui->tableView->setModel(model);
}
