#include "accountsettings.h"
#include "ui_accountsettings.h"
#include <QMessageBox>
#include "authorization.h"
AccountSettings::AccountSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountSettings)
{
    ui->setupUi(this);
    database.db_connect();
    ui->change_email->setPlaceholderText(QObject::tr("Введіть нову пошту"));
    ui->change_name->setPlaceholderText(QObject::tr("Введіть новий логін"));
    ui->change_pas->setPlaceholderText(QObject::tr("Введіть новий пароль"));

}

void AccountSettings::slot(QString a)
{
    login = a;
    QString s = "SELECT id from caligula_users.Users WHERE login="+login+";";
    QSqlQuery query = database.query_func(s);
    query.first();
    id = query.value(0).toString();
    qDebug() << id;

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
    int result = 1;
    QString login_n = ui->change_name->text();
    QString s = "SELECT login from caligula_users.Users;";
    QSqlQuery query = database.query_func(s);
    while(query.next()){
        QString username = query.value(0).toString();
        if(username == login_n){
            result = 0;
        }
        else{

        }
    }
    if(result == 1){
        QString s = "UPDATE caligula_users.Users SET login= "+login_n+" WHERE (id ="+id+");";
        QSqlQuery query = database.query_func(s);
        QMessageBox msgBox;
        msgBox.setText("Логін успішно змінено!");
        msgBox.exec();

        hide();
        Authorization *auth_w;
        auth_w = new Authorization(this);
        auth_w->show();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Логін вже зайнятий");
        msgBox.exec();
    }
}

void AccountSettings::on_button_change_pas_clicked()
{
    QString pas_n = ui->change_pas->text();
    QString s = "UPDATE caligula_users.Users SET password= "+pas_n+" WHERE (id ="+id+");";
    QSqlQuery query = database.query_func(s);
    QMessageBox msgBox;
    msgBox.setText("Пароль успішно змінено!");
    msgBox.exec();

    hide();
    Authorization *auth_w;
    auth_w = new Authorization(this);
    auth_w->show();
}


void AccountSettings::on_button_change_email_clicked()
{
    int result = 1;
    QString email_n = ui->change_email->text();
    QString s = "SELECT email from caligula_users.Users;";
    QSqlQuery query = database.query_func(s);
    while(query.next()){
        QString email_user = query.value(0).toString();
        if(email_user == email_n){
            result = 0;
        }
        else{
        }
    }
    if(result == 1){

        QString s = "UPDATE caligula_users.Users SET email= "+email_n+" WHERE (id ="+id+");";
        QSqlQuery query = database.query_func(s);
        QMessageBox msgBox;
        msgBox.setText("Електрону адресу успішно змінено!");
        msgBox.exec();

    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Електронна адреса вже зайнята");
        msgBox.exec();
    }

}


void AccountSettings::on_button_exit_clicked()
{
    hide();
    Authorization *auth_w;
    auth_w = new Authorization(this);
    auth_w->show();
}
