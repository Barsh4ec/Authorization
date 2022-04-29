#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QMovie>
#include <QDebug>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    setWindowTitle("Реєстрація");

    ui-> RegLogin-> setPlaceholderText ("Введіть логін");
    ui-> Email-> setPlaceholderText ("Введіть пошту");
    ui-> RegPass-> setPlaceholderText ("Введіть пароль");
    ui-> RegPass1-> setPlaceholderText ("Повторіть пароль");
    ui-> RegPass-> setEchoMode (QLineEdit :: Password);
    ui-> RegPass1-> setEchoMode (QLineEdit :: Password);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("caligulas.c5gym54nkb1s.us-east-1.rds.amazonaws.com");
    db.setDatabaseName("caligula_users");
    db.setUserName("admin");
    db.setPassword("adminadmin");
    db.setPort(3306);

}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_Back_To_Authorization_clicked()
{
    ui->RegLogin->setText("");
    ui->Email->setText("");
    ui->RegPass->setText("");
    ui->RegPass1->setText("");
    this->close();
    emit firstWindow();
}

void RegistrationWindow::on_FinishRagistration_clicked()
{
    QString password = ui->RegPass->text();
    QString password2 = ui->RegPass1->text();
    QString email = ui->Email->text();
    QString login = ui->RegLogin->text();
    double balance = 0.00;

    if(db.open()){
        if((password == password2) && (sizeof(login) > 4 || sizeof(login) < 10) && (sizeof(email) > 4 || sizeof(email) < 10)
                && (sizeof(password) > 4 || sizeof(password) < 10)) {
            QSqlQuery qry;
            qry.prepare("INSERT INTO Users (login, email, password, balance)"
                        "Values (:login, :email, :password, :balance)");
            qry.bindValue(":login", login);
            qry.bindValue(":email", email);
            qry.bindValue(":password", password);
            qry.bindValue(":balance", balance);
            if (qry.exec()){
                qDebug() << "inserted";
            } else {
                qDebug() << "not inserted";
            }
            this->close();
            emit firstWindow();
        } else {
            ui->label_6->setStyleSheet("QLabel { background-color : #f2f2f2; color : black; font-size:20px}");
            ui->label_6->setText("Неправильна інформація!");
            ui->RegPass->setText("");
            ui->RegPass1->setText("");
            return;
        }
    } else {
        qDebug() << db.lastError();
    }
}


void RegistrationWindow::on_RegPassCheck_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked) {
        ui-> RegPass-> setEchoMode (QLineEdit :: Normal);
        ui-> RegPass1-> setEchoMode (QLineEdit :: Normal);
    } else {
        ui-> RegPass-> setEchoMode (QLineEdit :: Password);
        ui-> RegPass1-> setEchoMode (QLineEdit :: Password);
    }
}

