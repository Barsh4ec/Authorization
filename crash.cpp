#include "crash.h"
#include "ui_crash.h"
#include <QMessageBox>

Crash::Crash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Crash)
{
    ui->setupUi(this);
    setWindowTitle("Crash");
    this->resize(1040, 700);
    ui->summa_stavky->setPlaceholderText ("Сума ставки");
    ui->summa_stavky->setText(stavka);
    time = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
    timer->start(10);
}

Crash::~Crash()
{
    delete ui;
}

void Crash::TimerSlot()
{
    time++;
    ui->Result->setText(QString::number(time));
}

void Crash::on_BackToMain_clicked()
{
    this->close();
    emit crashWindow();
}

static int randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}

void Crash::slot(QString a, QString b)
{
    login = a;
    password = b;
    QString balance = ui->userbalance->text();

    QSqlQuery query(QSqlDatabase::database("MyConnect"));
    query.prepare(QString("SELECT * FROM Users WHERE login = :login AND password = :password"));

    query.bindValue(":balance", balance);
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if(!query.exec()){
        qDebug() << "balance_failed";
    } else {
        while(query.next()) {
            QString balanceFromDB = query.value(4).toString();
            QString usernameFromDB = query.value(1).toString();
            QString passwordFromDB = query.value(3).toString();

            if(usernameFromDB == login && passwordFromDB == password) {
                this->money = balanceFromDB;
                ui->userbalance->setText(balanceFromDB);
            } else {
                qDebug() << "balance failed";
            }
        }
    }
}

void Crash::on_plus_value_button_clicked()
{
    if (stavka.toDouble() < this->money.toDouble())
    {
        ui->warning->setText("");
        stavka = QString::number(stavka.toDouble() + this->plus.toDouble());
        ui->summa_stavky->setText(stavka);
    } else {
        ui->warning->setText("Недостатньо грошей!");
    }
}


void Crash::on_minus_value_button_clicked()
{
    if (stavka.toDouble() >= 2)
    {
        ui->warning->setText("");
        stavka = QString::number(stavka.toDouble() - this->plus.toDouble());
        ui->summa_stavky->setText(stavka);
    } else {
        ui->warning->setText("Ставка не може бути нижчою!");
    }
}


void Crash::on_max_value_button_clicked()
{
    ui->warning->setText("");
    stavka = QString::number(money.toDouble());
    ui->summa_stavky->setText(stavka);
}


void Crash::on_half_value_button_clicked()
{
    if (stavka.toDouble() >= 2)
    {
        ui->warning->setText("");
        stavka = QString::number(stavka.toDouble() / 2.0);
        ui->summa_stavky->setText(stavka);
    } else {
        ui->warning->setText("Ставка занадто низька!");
    }
}


void Crash::on_x2_value_button_clicked()
{
    if ((stavka.toDouble() * 2.0) <= this->money.toDouble())
    {
        ui->warning->setText("");
        stavka = QString::number(stavka.toDouble() * 2.0);
        ui->summa_stavky->setText(stavka);
    } else {
        ui->warning->setText("Недостатньо грошей!");
    }
}


void Crash::on_min_value_button_clicked()
{
    ui->warning->setText("");
    stavka = QString::number(1);
    ui->summa_stavky->setText(stavka);
}

void Crash::on_plus_coeficient_button_clicked()
{
    if (coeficient.toDouble() < 10)
    {
        ui->warning->setText("");
        coeficient = QString::number(coeficient.toDouble() + this->plus.toDouble());
        ui->summa_autostop->setText(coeficient);
    } else {
        ui->warning->setText("Завеликий коефіцієнт!");
    }
}

void Crash::on_minus_coeficient_button_clicked()
{
    if (coeficient.toDouble() >= 2)
    {
        ui->warning->setText("");
        coeficient = QString::number(coeficient.toDouble() - this->plus.toDouble());
        ui->summa_autostop->setText(coeficient);
    } else {
        ui->warning->setText("Замалий коефіцієнт!");
    }
}


void Crash::on_Play_button_clicked()
{
    double a = randomBetween(10, 100);
    a = a / 10;
    QString b = QString::number(a);
    ui->Result->setText(b);
    if(coeficient.toDouble() <= a)
    {
        money = QString::number(money.toDouble() + stavka.toDouble() * a);

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            QSqlQuery query = database.query_func(s);
        }
    } else {
        money = QString::number(money.toDouble() - stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            QSqlQuery query = database.query_func(s);
        }
    }
    QSqlQuery query(QSqlDatabase::database("MyConnect"));
    query.prepare(QString("SELECT * FROM Users WHERE login = :login AND password = :password"));

    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if(!query.exec()){
        qDebug() << "balance_failed";
    } else {
        while(query.next()) {
            QString balanceFromDB = query.value(4).toString();
            QString usernameFromDB = query.value(1).toString();
            QString passwordFromDB = query.value(3).toString();

            if(usernameFromDB == login && passwordFromDB == password) {
                this->money = balanceFromDB;
                ui->userbalance->setText(balanceFromDB);
            } else {
                qDebug() << "balance failed";
            }
        }
    }
}

