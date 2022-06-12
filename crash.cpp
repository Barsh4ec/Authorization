#include "crash.h"
#include "ui_crash.h"
#include <QMessageBox>

Crash::Crash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Crash)
{
    ui->setupUi(this);
    setWindowTitle("Crash");
    this->resize(1050, 650);
    ui->summa_stavky->setPlaceholderText(QObject::tr("Сума ставки"));
    ui->summa_stavky->setText(stavka);

}

Crash::~Crash()
{
    delete ui;
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
    ui->Result->setStyleSheet("color: #696969;");
    stavka = ui->summa_stavky->text();
    coeficient = ui->summa_autostop->text();
    if ((coeficient.toDouble()) <= 1 || coeficient.toDouble() > 10)
    {
        ui->warning->setText("Неправильний коефіцієнт!");
        return;
    }
    if ((stavka.toDouble()) > this->money.toDouble())
    {
        ui->warning->setText("Недостатньо грошей!");
        return;
    }
    if ((stavka.toDouble()) <= 0)
    {
        ui->warning->setText("Ставка не може бути нижчою одиниці!");
        return;
    }else {
        ui->warning->setText("");
    }
    double a = Generate_Coeficient();
    double i = 0;
    while(i <= a)
    {
        i += 0.01;
        QString b = QString::number(i);
        ui->Result->setText(b+"X"+"");
        Timer(10);
    }
    a = i;
    if(coeficient.toDouble() >= a - 1 && coeficient.toDouble() <= a + 1)
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
            ui->Result->setStyleSheet("color: #90FF75;");
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
        ui->Result->setStyleSheet("color: #F96161;");
    }
    ui->userbalance->setText(money);
}

double Crash::Generate_Coeficient()
{
    int index = randomBetween(0, 100);
    if(index <= 15) ////////////////  >1
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 1 + coef;
    }
    if(index > 15 && index <= 29) ////////////////  >2
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 2 + coef;
    }
    if(index > 29 && index <= 42) ////////////////  >3
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 3 + coef;
    }
    if(index > 42 && index <= 54) ////////////////  >4
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 4 + coef;
    }
    if(index > 54 && index <= 65) ////////////////  >5
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 5 + coef;
    }
    if(index > 65 && index <= 74) ////////////////  >6
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 6 + coef;
    }
    if(index > 74 && index <= 81) ////////////////  >7
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 7 + coef;
    }
    if(index > 81 && index <= 87) ////////////////  >8
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 8 + coef;
    }
    if(index > 87 && index <= 92) ////////////////  >9
    {
        double coef = randomBetween(0, 99);
        coef = coef / 100;
        return 9 + coef;
    }
    if(index > 92 && index <= 100) ////////////////  0.01
    {
        return 0.01;
    }
    return 0;
}
void Crash::Timer(int a)
{
    QEventLoop q;
    QTimer t;
    t.setSingleShot(true);
    connect(&t, SIGNAL(timeout()), &q, SLOT(quit()));
    t.start(a); // 5s timeout
    q.exec();
}


void Crash::on_info_clicked()
{
    QMessageBox::about(this, "Інформація", "Crash - це модернізована нашою командою популярна азартна гра, мента якої полягає в тому, що потрібно вибрати коефіцієнт від одного до десяти, та розпочати гру. У випадку випадіння коефіцієнта в діапазоні від -1 до +1 від вибраного вами коефіцієнта, ви переможете, та подвоїте вашу стаку на вибраний вами коефіцієнт");
}

