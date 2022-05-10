#include "accountsettings.h"
#include "ui_accountsettings.h"
#include <QMessageBox>
AccountSettings::AccountSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountSettings)
{
    ui->setupUi(this);
    database.db_connect();

}

AccountSettings::~AccountSettings()
{
    delete ui;
}



void AccountSettings::on_BackToMain_clicked()
{
    this->close();
    emit AccountSettWindow();

}


void AccountSettings::on_button_change_name_clicked()
{
    login = database.extract_log();
    int result = 1;
    QString login_n = ui->change_name->text();
    QString s = "SELECT login from caligula_users.Users;";
    QSqlQuery query = database.query_func(s);
    while(query.next()){
        QString username = query.value(0).toString();
        qDebug() << username << login_n;
        if(username == login_n){
            qDebug() <<"false";
            result = 0;
        }
        else{
            qDebug() <<"True";
        }
    }
    if(result == 1){

        QString s = "UPDATE caligula_users.Users SET login= "+login_n+" WHERE (login ="+login+");";
        qDebug() << s;
        QSqlQuery query = database.query_func(s);
        QMessageBox msgBox;
        msgBox.setText("Логін успішно змінено!");
        msgBox.exec();

    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Логін вже зайнятий");
        msgBox.exec();
    }
}
