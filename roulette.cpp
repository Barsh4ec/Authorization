#include "roulette.h"
#include "ui_roulette.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QPainter>
#include <cmath>

Roulette::Roulette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roulette)
{
    ui->setupUi(this);
    setWindowTitle("Roulette");
    this->resize(1040, 800);
    an_pix = new PixmapItem(QPixmap(":/resources/png/Roulette_wheel.png"));
    pointer = new PixmapItem(QPixmap(":/resources/png/Pointer.png"));
    scene = new QGraphicsScene(0, 0, 455, 455, this);
    ui->graphicsView->setFrameShape(QFrame::NoFrame);
    ui->graphicsView->setScene(scene);
    scene->addItem(an_pix);
    scene->addItem(pointer);
    pointer->setPos(175, -13);
    pointer->setZValue(1);

    time = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));

    ui->summa_stavky->setPlaceholderText ("Сума ставки");
    ui->summa_stavky->setText(stavka);
}

Roulette::~Roulette()
{
    delete ui;
}


void Roulette::TimerSlot()
{
   time++;
   ui->label->setText(QString::number(time));
}
static int randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}
void Roulette::ChangeHistory(QString a, QString b)
{
    QString tmp[8][2];
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 2; j++)
            tmp[i][j] = history[i][j];
    }
    tmp[0][0] = a;
    tmp[0][1] = b;
    for(int i = 1; i < 8; i++)
    {
        for(int j = 0; j < 2; j++)
            tmp[i][j] = history[i -1][j];
    }
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 2; j++)
            history[i][j] = tmp[i][j];
    }
    ui->history1->setStyleSheet("QLabel { background-color : "+history[0][0]+"; text-align: center; color : white; font-size:20px; border-radius: 20px;}");
    ui->history1->setText(history[0][1]);
    ui->history2->setStyleSheet("QLabel { background-color : "+history[1][0]+"; color : white; font-size:20px; border-radius: 20px; text-align: center}");
    ui->history2->setText(history[1][1]);
    ui->history3->setStyleSheet("QLabel { background-color : "+history[2][0]+"; color : white; font-size:20px; border-radius: 20px; text-align: center}");
    ui->history3->setText(history[2][1]);
    ui->history4->setStyleSheet("QLabel { background-color : "+history[3][0]+"; color : white; font-size:20px; border-radius: 20px; text-align: center}");
    ui->history4->setText(history[3][1]);
    ui->history5->setStyleSheet("QLabel { background-color : "+history[4][0]+"; color : white; font-size:20px; border-radius: 20px; text-align: center}");
    ui->history5->setText(history[4][1]);
    ui->history6->setStyleSheet("QLabel { background-color : "+history[5][0]+"; color : white; font-size:20px; border-radius: 20px; text-align: center}");
    ui->history6->setText(history[5][1]);
    ui->history7->setStyleSheet("QLabel { background-color : "+history[6][0]+"; color : white; font-size:20px; border-radius: 20px; text-align: center}");
    ui->history7->setText(history[6][1]);
    ui->history8->setStyleSheet("QLabel { background-color : "+history[7][0]+"; color : white; font-size:20px; border-radius: 20px; text-align: center}");
    ui->history8->setText(history[7][1]);
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
    if ((stavka.toDouble()) <= this->money.toDouble())
    {
        ui->warning->setText("");
    } else {
        ui->warning->setText("Недостатньо грошей!");
        return;
    }


    tmp1 = tmp2;
    int random = randomBetween(0, 14);
    tmp2 = random;
    QString res = mas[random][0];
    int speed = MakeTime(tmp1, tmp2);
    Speen_Wheel(speed);
    if(res == "red"){
        ChangeHistory("#F96161", mas[random][1]);    /////////////якщо червоний колір


        money = QString::number(money.toDouble() + stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
        }
    } else {
        if(res == "black"){
            ChangeHistory("#242323", mas[random][1]); //// якщо чорний колір
        }
        if(res == "green"){
            ChangeHistory("#90FF75", mas[random][1]);     ////////////якщо зелений колір
        }


        money = QString::number(money.toDouble() - stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
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
    if ((stavka.toDouble()) <= this->money.toDouble())
    {
        ui->warning->setText("");
    } else {
        ui->warning->setText("Недостатньо грошей!");
        return;
    }


    tmp1 = tmp2;
    int random = randomBetween(0, 14);
    tmp2 = random;
    QString res = mas[random][0];
    int speed = MakeTime(tmp1, tmp2);
    Speen_Wheel(speed);
    if(res == "black"){
        ChangeHistory("#242323", mas[random][1]); //// якщо чорний колір

        money = QString::number(money.toDouble() + stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
        }
    } else {
        if(res == "red"){
            ChangeHistory("#F96161", mas[random][1]);     /////////////якщо червоний колір
        }
        if(res == "green"){
            ChangeHistory("#90FF75", mas[random][1]);     ////////////якщо зелений колір
        }


        money = QString::number(money.toDouble() - stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
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
    if ((stavka.toDouble()) <= this->money.toDouble())
    {
        ui->warning->setText("");
    } else {
        ui->warning->setText("Недостатньо грошей!");
        return;
    }


    tmp1 = tmp2;
    int random = randomBetween(0, 14);
    tmp2 = random;
    QString res = mas[random][0];
    int speed = MakeTime(tmp1, tmp2);
    Speen_Wheel(speed);
    if(res == "green"){
        ChangeHistory("#90FF75", mas[random][1]); //////////// Якщо зелений колір


        money = QString::number(money.toDouble() + stavka.toDouble() * 14);

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
        }


    } else {
        if(res == "red"){
            ChangeHistory("#F96161", mas[random][1]); /////////////якщо червоний колір
        }
        if(res == "black"){
            ChangeHistory("#242323", mas[random][1]); //////////// якщо чорний колір
        }


        money = QString::number(money.toDouble() - stavka.toDouble());

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1){

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
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
    QMessageBox::about(this, "Інформація", "Рулетка (від фр. roulette — «коліщатко») — різновид однієї з азартних ігор, основний атрибут казино. "
                                           "Все що вам необхідно зробити, це вибрати суму, на яку ви бажаєте грати, зробити ставку на один з трьох кольорів, "
                                           "та очікувати зупинки колеса. У разі виграшу ваша ставка подвоється, та виграні гроші поступлять на баланс вашого рахунку!");
}

void Roulette::Timer(int a)
{
    QEventLoop q;
    QTimer t;
    t.setSingleShot(true);
    connect(&t, SIGNAL(timeout()), &q, SLOT(quit()));
    t.start(a); // 5s timeout
    q.exec();
}

void Roulette::Speen_Wheel(int a)
{
    int t = randomBetween(3, 6);
    int dodatkovyoberty = t * 360;
    int obert = dodatkovyoberty + a;
    while(position >= 360)
    {
        position = position - 360;
    }
    obert = obert + position;

    pointer = new PixmapItem(QPixmap(":/resources/png/Pointer.png"));
    an_pix = new PixmapItem(QPixmap(":/resources/png/Roulette_wheel.png"));

    m_anim = new QPropertyAnimation(an_pix,"rotate",this);
    m_anim->setEasingCurve(QEasingCurve::Linear);
    m_anim->setStartValue(qreal(position));
    m_anim->setEndValue(qreal(obert));
    m_anim->setDuration(6000);
    m_anim->setDirection(QAbstractAnimation::Forward);
    m_anim->start();

    scene = new QGraphicsScene(0, 0, 455, 455, this);
    ui->graphicsView->setScene(scene);
    scene->addItem(an_pix);
    scene->addItem(pointer);
    pointer->setPos(175, -16);
    pointer->setZValue(1);
    position = obert;
    Timer(6050);
}

int Roulette::MakeTime(int first, int second)
{
    int tmp = first- second;
    if(tmp < 0)
        tmp = tmp + 15;
    switch (tmp)
    {
    case 0:
        return 0;
       break;
    case 1:
        return 24;
        break;
    case 2:
        return 48;
        break;
    case 3:
        return 72;
        break;
    case 4:
        return 96;
        break;
    case 5:
        return 120;
        break;
    case 6:
        return 144;
        break;
    case 7:
        return 168;
        break;
    case 8:
        return 192;
        break;
    case 9:
        return 216;
        break;
    case 10:
        return 240;
        break;
    case 11:
        return 264;
        break;
    case 12:
        return 288;
        break;
    case 13:
        return 312;
        break;
    case 14:
        return 336;
        break;
    }
    return 0;
}
