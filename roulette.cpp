#include "roulette.h"
#include "ui_roulette.h"
#include <QMessageBox>

Roulette::Roulette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roulette)
{
    ui->setupUi(this);
    setWindowTitle("Roulette");
    this->resize(1040, 800);

    ui->summa_stavky->setPlaceholderText ("Сума ставки");
    ui->summa_stavky->setText(stavka);
}

Roulette::~Roulette()
{
    delete ui;
}

static int randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}
void Roulette::ChangeHistory(QString a)
{
    QString tmp[8];
    for(int i = 0; i < 8; i++)
    {
        tmp[i] = history[i];
    }
    tmp[0] = a;
    for(int i = 1; i < 8; i++)
    {
        tmp[i] = history[i -1];
    }
    for(int i = 0; i < 8; i++)
    {
        history[i] = tmp[i];
    }
    ui->history1->setStyleSheet("QLabel { background-color : "+history[0]+"; color : black; font-size:16px; border-radius: 20px}");
    ui->history2->setStyleSheet("QLabel { background-color : "+history[1]+"; color : black; font-size:16px; border-radius: 20px}");
    ui->history3->setStyleSheet("QLabel { background-color : "+history[2]+"; color : black; font-size:16px; border-radius: 20px}");
    ui->history4->setStyleSheet("QLabel { background-color : "+history[3]+"; color : black; font-size:16px; border-radius: 20px}");
    ui->history5->setStyleSheet("QLabel { background-color : "+history[4]+"; color : black; font-size:16px; border-radius: 20px}");
    ui->history6->setStyleSheet("QLabel { background-color : "+history[5]+"; color : black; font-size:16px; border-radius: 20px}");
    ui->history7->setStyleSheet("QLabel { background-color : "+history[6]+"; color : black; font-size:16px; border-radius: 20px}");
    ui->history8->setStyleSheet("QLabel { background-color : "+history[7]+"; color : black; font-size:16px; border-radius: 20px}");
}
void Roulette::on_BackToMain_clicked()
{
    this->close();
    emit fWindow();
}
void Roulette::slot(QString a, QString b)
{
    login = a;
    password = b;
    qDebug() << login;
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
                qDebug() << "balance success!";
                this->money = balanceFromDB;
                ui->userbalance->setText(balanceFromDB);
            } else {
                qDebug() << "balance failed";
            }
        }
    }
}

void Roulette::on_plus_value_button_clicked()
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


void Roulette::on_minus_value_button_clicked()
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


void Roulette::on_max_value_button_clicked()
{
    ui->warning->setText("");
    stavka = QString::number(money.toDouble());
    ui->summa_stavky->setText(stavka);
}


void Roulette::on_half_value_button_clicked()
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


void Roulette::on_x2_value_button_clicked()
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


void Roulette::on_min_value_button_clicked()
{
    ui->warning->setText("");
    stavka = QString::number(1);
    ui->summa_stavky->setText(stavka);
}


void Roulette::on_bet_on_red_clicked()
{
    int random = randomBetween(0, 15);
    qDebug() << random;
    QString res = mas[random];
    qDebug() << res;
    if(res == "red"){
        ChangeHistory("#F96161");     /////////////якщо червоний колір


        ui->temporary_result->setText("Випало червоне!");


        money = QString::number(money.toDouble() + stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            qDebug() << s;
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
        }
    } else {
        if(res == "black"){
            ui->temporary_result->setText("Випало чорне!");
            ChangeHistory("#242323"); //// якщо чорний колір
        }
        if(res == "green"){
            ui->temporary_result->setText("Випало зелене!");
            ChangeHistory("#90FF75");     ////////////якщо зелений колір
        }


        money = QString::number(money.toDouble() - stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            qDebug() << s;
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
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
                qDebug() << "balance success!";
                this->money = balanceFromDB;
                ui->userbalance->setText(balanceFromDB);
            } else {
                qDebug() << "balance failed";
            }
        }
    }
}


void Roulette::on_bet_on_black_clicked()
{
    int random = randomBetween(0, 15);
    qDebug() << random;
    QString res = mas[random];
    qDebug() << res;
    if(res == "black"){
        ChangeHistory("#242323"); //// якщо чорний колір


        ui->temporary_result->setText("Випало чорне!");


        money = QString::number(money.toDouble() + stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            qDebug() << s;
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
        }
    } else {
        if(res == "red"){
            ui->temporary_result->setText("Випало червоне!");
            ChangeHistory("#F96161");     /////////////якщо червоний колір
        }
        if(res == "green"){
            ui->temporary_result->setText("Випало зелене!");
            ChangeHistory("#90FF75");     ////////////якщо зелений колір
        }


        money = QString::number(money.toDouble() - stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            qDebug() << s;
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
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
                qDebug() << "balance success!";
                this->money = balanceFromDB;
                ui->userbalance->setText(balanceFromDB);
            } else {
                qDebug() << "balance failed";
            }
        }
    }
}


void Roulette::on_bet_on_green_clicked()
{
    int random = randomBetween(0, 15);
    qDebug() << random;
    QString res = mas[random];
    qDebug() << res;
    if(res == "green"){
        ChangeHistory("#90FF75"); //////////// Якщо зелений колір


        ui->temporary_result->setText("Випало зелене!");


        money = QString::number(money.toDouble() + stavka.toDouble() * 14);

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            qDebug() << s;
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
        }


    } else {
        if(res == "red"){
            ui->temporary_result->setText("Випало червоне!");
            ChangeHistory("#F96161"); /////////////якщо червоний колір
        }
        if(res == "black"){
            ui->temporary_result->setText("Випало чорне!");
            ChangeHistory("#242323"); //////////// якщо чорний колір
        }


        money = QString::number(money.toDouble() - stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            qDebug() << s;
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
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
                qDebug() << "balance success!";
                this->money = balanceFromDB;
                ui->userbalance->setText(balanceFromDB);
            } else {
                qDebug() << "balance failed";
            }
        }
    }
}


void Roulette::on_info_clicked()
{

}

