#include "widget.h"
#include "ui_widget.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mDb = QSqlDatabase::addDatabase("QMYSQL");
    mDb.setHostName("localhost");
    mDb.setDatabaseName("test1");
    mDb.setPort(3306);
    mDb.setUserName("root");
    mDb.setPassword("1234");

    if (!mDb.open())
    {
        QMessageBox::critical(this, "Error", mDb.lastError().text());
        return;
    }

    mModel = new QSqlTableModel(this);
    mModel->setTable("table1");
    mModel->select();
    ui->tableView->setModel(mModel);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_but_add_clicked()
{
    mModel->insertRow(mModel->rowCount());
}

void Widget::on_but_delete_clicked()
{
    mModel->removeRow(ui->tableView->currentIndex().row());
}

void Widget::on_but_update_clicked()
{
    mModel->select();
}
