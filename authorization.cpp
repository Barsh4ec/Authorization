#include "authorization.h"
#include "ui_authorization.h"
#include <iostream>
#include <QMessageBox>
#include <QMovie>
#include <QDebug>

Authorization::Authorization(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Authorization)
{
    ui->setupUi(this);

    setWindowTitle("Авторизація");

    sWindow = new RegistrationWindow();
    connect(sWindow, &RegistrationWindow::firstWindow, this, &Authorization::show);
    ui-> Login-> setPlaceholderText ("Введіть логін");
    ui-> password-> setPlaceholderText ("Введіть пароль");
    ui-> password-> setEchoMode (QLineEdit :: Password);

    database = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
    database.setHostName("caligulas.c5gym54nkb1s.us-east-1.rds.amazonaws.com");
    database.setDatabaseName("caligula_users");
    database.setUserName("admin");
    database.setPassword("adminadmin");
    database.setPort(3306);

}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::on_RegistrationButton_clicked()
{
    ui->Login->setText("");
    ui->password->setText("");
    sWindow->show();
    this->close();
}
void Authorization::on_EnterButton_clicked()
{
    login = ui->Login->text();
    password = ui->password->text();
    if(database.open()) {
        qDebug() << "success!";

        QSqlQuery query(QSqlDatabase::database("MyConnect"));
        query.prepare(QString("SELECT * FROM Users WHERE login = :login AND password = :password"));

        query.bindValue(":login", login);
        query.bindValue(":password", password);

        if(!query.exec()){
            qDebug() << "failed";
        } else {
            while(query.next()) {
                QString usernameFromDB = query.value(1).toString();
                QString passwordFromDB = query.value(3).toString();

                if(usernameFromDB == login && passwordFromDB == password) {
                    qDebug() << "login success!";
                    this->close();
                    mWindow = new MainWindow(this, login, password);
                    mWindow->show();
                } else {
                    qDebug() << "login failed";
                }
            }
        }
    } else {
        qDebug() << "database connection failed";
    }

}

void Authorization::on_CheckPass_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked) {
        ui-> password-> setEchoMode (QLineEdit :: Normal);
    } else {
        ui-> password-> setEchoMode (QLineEdit :: Password);
    }
}
