#include "addmoney.h"
#include "ui_addmoney.h"
#include <QMessageBox>

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
void AddMoney::balance_func(QString amount, QString promo, QString bill){
    QString result = "F";
    QString promo_end;
    for(int i = 0; i < 4; i++){
            if(promos[i] == promo){
                promo_end = promo;
                result = "T";
            };
        }
    if(result == "F" && promo != ""){
        QMessageBox msgBox;
        msgBox.setText("Такого коду не існує");
        msgBox.exec();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Успішно поповнено рахунок");
        msgBox.exec();
        if (promo_end == ""){
            amount = QString::number(amount.toInt() + bill.toInt());
            qDebug()<<amount;
        }
        else{
        amount = QString::number(amount.toInt() + bill.toInt() + (bill.toInt() * promo_end.toInt() / 100));
        }
        QString s = "UPDATE caligula_users.Users SET balance= "+amount+" WHERE (login ="+login+");";
        QSqlQuery query = database.query_func(s);

  }
}


void AddMoney::slot(QString a)
{
    login = a;
    QString s = "SELECT balance from caligula_users.Users WHERE login="+login+";";
    QSqlQuery query = database.query_func(s);
    query.first();
    amount = query.value(0).toString();

}

void AddMoney::on_pushButton_clicked()
{
    QString bill = ui->lineEdit_2->text();
    QString promo = ui->lineEdit->text();
    balance_func(amount, promo,bill);

}


