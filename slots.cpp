#include "slots.h"
#include "ui_slots.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QPainter>
#include <cmath>
#include <QDebug>

Slots::Slots(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Slots)
{
    ui->setupUi(this);
    setWindowTitle("Slots");
    this->resize(1040, 700);
}

Slots::~Slots()
{
    delete ui;
}

void Slots::on_BackToMain_clicked()
{
    this->close();
    emit slotsWindow();
}

void Slots::on_StartGame_clicked()
{
    if(is_started == true)
        return;
    stavka = ui->summa_stavky->text();
    if ((stavka.toDouble()) <= this->money.toDouble() && stavka != "0" )
    {
        ui->warning->setText("");
    } else {
        ui->warning->setText("Недостатньо грошей!");
        return;
    }
    is_started = true;
    QString WinMoney;
    ui->Win->setText("");
    ui->label_1->setStyleSheet("background-image:");
    ui->label_2->setStyleSheet("background-image:");
    ui->label_3->setStyleSheet("background-image:");
    int Picture1 = RandomPicture1();
    int Picture2 = RandomPicture2();
    int Picture3 = RandomPicture3();
    if((Picture1 == Picture2 && Picture1 != Picture3)
            || (Picture1 == Picture3 && Picture1 != Picture2)
            || (Picture2 == Picture3 && Picture2 != Picture1))
    {
        money = QString::number(money.toDouble() + stavka.toDouble() * 10);
        WinMoney = QString::number(stavka.toDouble() * 5);
        ui->Win->setText(WinMoney);
        ui->userbalance->setText(money);

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
        is_started = false;
        return;
    }else if((Picture1 == Picture2) && (Picture1 == Picture3) )
    {
        money = QString::number(money.toDouble() + stavka.toDouble() * 50);
        WinMoney = QString::number(stavka.toDouble() * 50);
        ui->Win->setText(WinMoney);
        ui->userbalance->setText(money);

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1)
        {

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
        }
        is_started = false;
        return;
    } else {
        money = QString::number(money.toDouble() - stavka.toDouble());
        ui->userbalance->setText(money);

        int result = 1;
        QString s = "SELECT login AND balance from caligula_users.Users;";
        QSqlQuery query = database.query_func(s);
        while(query.next()){
        }
        if(result == 1)
        {

            QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
            QSqlQuery query = database.query_func(s);
            QMessageBox msgBox;
            msgBox.setText("гроші успішно змінено!");
        }
        is_started = false;
    return;
    }
}

void Slots::slot(QString a, QString b)
{
    login = a;
    password = b;
    QString balance = ui->userbalance->text();
    QString s = "SELECT balance FROM caligula_users.Users WHERE login = "+login+";";
    QSqlQuery query = database.query_func(s);
    while (query.next())
    {
       QString balanceFromDB = query.value(0).toString();
        this->money = balanceFromDB;
        ui->userbalance->setText(balanceFromDB);
    }
}


int Slots::RandomPicture1()
{
    int random;
    QString res1;
    for(int i = 0; i<=700; i+=50)
    {
        random = randomBetween(0, 7);
        res1 = mas[random];
        ui->label_1->setStyleSheet("background-image: url("+res1+")");
        Timer(i);
    }
    return random;
}
int Slots::RandomPicture2()
{
    int random;
    QString res1;
    for(int i = 0; i<=700; i+=50)
    {
        random = randomBetween(0, 7);
        res1 = mas[random];
        ui->label_2->setStyleSheet("background-image: url("+res1+")");
        // ("B"+ryad+"_"+stovpec+")
        Timer(i);
    }
    return random;
}
int Slots::RandomPicture3()
{
    int random;
    QString res1;
    for(int i = 0; i<=700; i+=50)
    {
        random = randomBetween(0, 7);
        res1 = mas[random];
        ui->label_3->setStyleSheet("background-image: url("+res1+")");
        Timer(i);
    }
    return random;
}
void Slots::RandomGenerate()
{
    int random = randomBetween(0, 7);
    QString res1 = mas[random];
    qDebug()<<res1;
    ui->label_1->setStyleSheet("background-image: url("+res1+")");

}
int Slots:: randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}

void Slots::Timer(int a)
{
    QEventLoop q;
    QTimer t;
    t.setSingleShot(true);
    connect(&t, SIGNAL(timeout()), &q, SLOT(quit()));
    t.start(a); // 5s timeout
    q.exec();
}


void Slots::on_info_clicked()
{
 QMessageBox::about(this, "Інформація", "Слот-машиина — різновид ігрових автоматів для азартної гри. "
                                        "Ігри для таких автоматів також називаються «слотами», у кожної з таких ігор є своя власна назва."
                                        " У них можна грати не тільки на слот-машині, але й на комп'ютері, встановивши спеціальне програмне забезпечення або ж у режимі онлайн."
                                        " Слоти користуються величезною популярністю в казино, як «реальних», так і в інтернеті."
                                        "\n=======================================================================================\n"
                                        "\nКомбінації: "
                                        "\n3 одинакові картинки = виграш Х 50\n"
                                        "2 одинакові картинки = виграш Х 5\n"
                                        "\n=======================================================================================\n "
                                        );
}

