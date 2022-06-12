#include "minesweeper.h"
#include "ui_minesweeper.h"
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>

int empty_fields = 0;
bool start_stop = false;

Minesweeper::Minesweeper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Minesweeper)
{
    ui->setupUi(this);
    setWindowTitle("Minesweeper");
    this->resize(1040, 700);
}

Minesweeper::~Minesweeper()
{
    delete ui;
}

void Minesweeper::on_BackToMain_clicked()
{
    this->close();
    emit minesWindow();
}

void Minesweeper::slot(QString a)
{
    login = a;
    QString s = "SELECT balance FROM caligula_users.Users WHERE login = "+login+";";
    QSqlQuery query = database.query_func(s);
    while (query.next())
    {
       QString balanceFromDB = query.value(0).toString();
        this->money = balanceFromDB;
        ui->balance_label->setText(balanceFromDB);
    }
}

bool Minesweeper::CheckField(int a, int b)
{
    if(start_stop == false)
        return true;
    if(mas[a][b] == true)
    {

        empty_fields++;
        coeficient = QString::number(MakeCoeficient(bombs.toInt(), empty_fields));
        ui->coeficient_label->setText(coeficient);
        return true;
    }
    else
    {
        start_stop = false;
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
        ui->balance_label->setText(money);
        coeficient = "1";
        ui->coeficient_label->setText("1");
        empty_fields = 0;
        return false;
    }
}

void Minesweeper::on_PlayButton_clicked()
{
    stavka = ui->summa_stavky->text();
    if ((stavka.toDouble()) <= this->money.toDouble() && stavka != "0" )
    {
        ui->warning->setText("");
    } else {
        ui->warning->setText("Недостатньо грошей!");
        return;
    }
    int a = 0;
    int b = 0;
    QString bombs = ui->bomb_count->text();
    int bombs_count = bombs.toInt();
    int i = 0;
    while (i<bombs_count)
    {
        a = RandomBetween(0, 2);
        b = RandomBetween(0, 4);

        if(mas[a][b] == true)
        {
           mas[a][b] = false;
           i++;
        }
    }
    ui->PlayButton->lower();
    ui->StopButton->raise();
    start_stop = true;
}

int Minesweeper:: RandomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}

void Minesweeper::on_plus_value_button_clicked()
{
    if(start_stop == true)
        return;
    if (bombs.toDouble() < this->max_bombs.toDouble())
    {
        ui->warning->setText("");
        bombs = QString::number(bombs.toDouble() + this->plus.toDouble());
        ui->bomb_count->setText(bombs);
    } else {
        ui->warning->setText("Це максимальна кількість бомб!");
    }
}

void Minesweeper::on_minus_value_button_clicked()
{
    if(start_stop == true)
        return;
    if (bombs.toDouble() >= 2)
    {
        ui->warning->setText("");
        bombs = QString::number(bombs.toDouble() - this->plus.toDouble());
        ui->bomb_count->setText(bombs);
    } else {
        ui->warning->setText("Кількість бомб не може бути нижчою!");
    }
}

void Minesweeper::on_StopButton_clicked()
{
    RecoverButtons();
    ui->PlayButton->raise();
    ui->StopButton->lower();

    money = QString::number(money.toDouble() + stavka.toDouble() * coeficient.toDouble());

    int result = 1;
    QString s = "SELECT login AND balance from caligula_users.Users;";
    QSqlQuery query = database.query_func(s);
    while(query.next()){
    }
    if(result == 1){

        QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
        QSqlQuery query = database.query_func(s);
    }
    ui->balance_label->setText(money);

    start_stop = false;
    coeficient = "1";
    ui->coeficient_label->setText("1");
    empty_fields = 0;
}

double Minesweeper::MakeCoeficient(int first, int second)
{
    double tmp = (double)first * ((double)second / 3);
    return tmp;
}
void Minesweeper::Timer(int a)
{
    QEventLoop q;
    QTimer t;
    t.setSingleShot(true);
    connect(&t, SIGNAL(timeout()), &q, SLOT(quit()));
    t.start(a);
    q.exec();
}
void Minesweeper::on_b1_1_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(0, 0);
        if(check == false)
        {
            ui->b1_1->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b1_1->setStyleSheet("background-color: #E3FCBF");
            ui->b1_1->setEnabled(false);
        }
    }
}
void Minesweeper::on_b1_2_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(1, 0);
        if(check == false)
        {
            ui->b1_2->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b1_2->setStyleSheet("background-color: #E3FCBF");
            ui->b1_2->setEnabled(false);
        }
    }
}
void Minesweeper::on_b1_3_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(2, 0);
        if(check == false)
        {
            ui->b1_3->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b1_3->setStyleSheet("background-color: #E3FCBF");
            ui->b1_3->setEnabled(false);
        }
    }
}
void Minesweeper::on_b2_1_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(0, 1);
        if(check == false)
        {
            ui->b2_1->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b2_1->setStyleSheet("background-color: #E3FCBF");
            ui->b2_1->setEnabled(false);
        }
    }
}
void Minesweeper::on_b2_2_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(1, 1);
        if(check == false)
        {
            ui->b2_2->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b2_2->setStyleSheet("background-color: #E3FCBF");
            ui->b2_2->setEnabled(false);
        }
    }
}
void Minesweeper::on_b2_3_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(2, 1);
        if(check == false)
        {
            ui->b2_3->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b2_3->setStyleSheet("background-color: #E3FCBF");
            ui->b2_3->setEnabled(false);
        }
    }
}
void Minesweeper::on_b3_1_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(0, 2);
        if(check == false)
        {
            ui->b3_1->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b3_1->setStyleSheet("background-color: #E3FCBF");
            ui->b3_1->setEnabled(false);
        }
    }
}
void Minesweeper::on_b3_2_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(1, 2);
        if(check == false)
        {
            ui->b3_2->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b3_2->setStyleSheet("background-color: #E3FCBF");
            ui->b3_2->setEnabled(false);
        }
    }
}
void Minesweeper::on_b3_3_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(2, 2);
        if(check == false)
        {
            ui->b3_3->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b3_3->setStyleSheet("background-color: #E3FCBF");
            ui->b3_3->setEnabled(false);
        }
    }
}
void Minesweeper::on_b4_1_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(0, 3);
        if(check == false)
        {
            ui->b4_1->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b4_1->setStyleSheet("background-color: #E3FCBF");
            ui->b4_1->setEnabled(false);
        }
    }
}
void Minesweeper::on_b4_2_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(1, 3);
        if(check == false)
        {
            ui->b4_2->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b4_2->setStyleSheet("background-color: #E3FCBF");
            ui->b4_2->setEnabled(false);
        }
    }
}
void Minesweeper::on_b4_3_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(2, 3);
        if(check == false)
        {
            ui->b4_3->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b4_3->setStyleSheet("background-color: #E3FCBF");
            ui->b4_3->setEnabled(false);
        }
    }
}
void Minesweeper::on_b5_1_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(0, 4);
        if(check == false)
        {
            ui->b5_1->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b5_1->setStyleSheet("background-color: #E3FCBF");
            ui->b5_1->setEnabled(false);
        }
    }
}
void Minesweeper::on_b5_2_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(1, 4);
        if(check == false)
        {
            ui->b5_2->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b5_2->setStyleSheet("background-color: #E3FCBF");
            ui->b5_2->setEnabled(false);
        }
    }
}
void Minesweeper::on_b5_3_clicked()
{
    if(start_stop == true)
    {
        bool check = CheckField(2, 4);
        if(check == false)
        {
            ui->b5_3->setStyleSheet("background-image: url(:/resources/png/Explosion.png)");
            Timer(1000);
            RecoverButtons();
            ui->PlayButton->raise();
            ui->StopButton->lower();
        }
        else
        {
            ui->b5_3->setStyleSheet("background-color: #E3FCBF");
            ui->b5_3->setEnabled(false);
        }
    }
}

void Minesweeper::RecoverButtons()
{
    mas[0][0] = true;
    mas[1][0] = true;
    mas[2][0] = true;
    mas[0][1] = true;
    mas[1][1] = true;
    mas[2][1] = true;
    mas[0][2] = true;
    mas[1][2] = true;
    mas[2][2] = true;
    mas[0][3] = true;
    mas[1][3] = true;
    mas[2][3] = true;
    mas[0][4] = true;
    mas[1][4] = true;
    mas[2][4] = true;
    ui->b1_1->setStyleSheet("background-image:");
    ui->b1_1->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b1_1->setEnabled(true);
    ui->b1_2->setStyleSheet("background-image:");
    ui->b1_2->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b1_2->setEnabled(true);
    ui->b1_3->setStyleSheet("background-image:");
    ui->b1_3->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b1_3->setEnabled(true);
    ui->b2_1->setStyleSheet("background-image:");
    ui->b2_1->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b2_1->setEnabled(true);
    ui->b2_2->setStyleSheet("background-image:");
    ui->b2_2->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b2_2->setEnabled(true);
    ui->b2_3->setStyleSheet("background-image:");
    ui->b2_3->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b2_3->setEnabled(true);
    ui->b3_1->setStyleSheet("background-image:");
    ui->b3_1->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b3_1->setEnabled(true);
    ui->b3_2->setStyleSheet("background-image:");
    ui->b3_2->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b3_2->setEnabled(true);
    ui->b3_3->setStyleSheet("background-image:");
    ui->b3_3->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b3_3->setEnabled(true);
    ui->b4_1->setStyleSheet("background-image:");
    ui->b4_1->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b4_1->setEnabled(true);
    ui->b4_2->setStyleSheet("background-image:");
    ui->b4_2->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b4_2->setEnabled(true);
    ui->b4_3->setStyleSheet("background-image:");
    ui->b4_3->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b4_3->setEnabled(true);
    ui->b5_1->setStyleSheet("background-image:");
    ui->b5_1->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b5_1->setEnabled(true);
    ui->b5_2->setStyleSheet("background-image:");
    ui->b5_2->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b5_2->setEnabled(true);
    ui->b5_3->setStyleSheet("background-image:");
    ui->b5_3->setStyleSheet("background-color: rgb(46, 229, 157)");
    ui->b5_3->setEnabled(true);
}

void Minesweeper::on_info_clicked()
{
    QMessageBox::about(this, "Інформація", "Minesweeper - логічна головоломка з елементами тактики. Вам належить насолоджуватися класичним зовнішнім виглядом гри, де головне відкривати квадратики і не потрапити на міну.");
}
