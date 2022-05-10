#include "addmoney.h"
#include "ui_addmoney.h"

AddMoney::AddMoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMoney)
{
    ui->setupUi(this);
}

AddMoney::~AddMoney()
{
    delete ui;
}

void AddMoney::on_back_to_main_clicked()
{
    this->close();
    emit addMWindow();
}

void AddMoney::slot(QString a)
{
    login = a;
    qDebug() << login;
}
