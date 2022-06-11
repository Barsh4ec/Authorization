#include "hilo.h"
#include "ui_hilo.h"
#include <QMessageBox>

HiLo::HiLo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HiLo)
{
    ui->setupUi(this);
    setWindowTitle("HiLo");
    this->resize(1150, 700);
    ChangeTheCard();
    is_plus = true;
    ui->coeficient_label->setText(Total_coeficient);
    ui->count_of_cards_label->setText(cards_in_row);

}

HiLo::~HiLo()
{
    delete ui;
}

void HiLo::on_BackToMain_clicked()
{
    this->close();
    emit HiLoWindow();
}

static int randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}

int HiLo::ChangeTheCard()
{
    int tmp_index = index;
    while(index == tmp_index)
    {
        index = randomBetween(0, 12);
    }
    int type_of_card = randomBetween(1, 4);
    switch(type_of_card)
    {
    case(1):
        ui->Current_card->setStyleSheet("background: url("+bubna[index]+");");
        break;
    case(2):
        ui->Current_card->setStyleSheet("background: url("+cherva[index]+");");
        break;
    case(3):
        ui->Current_card->setStyleSheet("background: url("+pika[index]+");");
        break;
    case(4):
        ui->Current_card->setStyleSheet("background: url("+hresta[index]+");");
        break;
    }

    high_coeficient = MakeHighCoeficient(index);
    QString str_hcoef = QString::number(high_coeficient);
    ui->Higher_card_Button->setText(""+str_hcoef+"X");
    low_coeficient = MakeLowCoeficient(index);
    QString str_lcoef = QString::number(low_coeficient);
    ui->Lower_Card_Button->setText(""+str_lcoef+"X");
    return index;
}

void HiLo::slot(QString a)
{
    login = a;
    QString balance = ui->userbalance->text();

    QSqlQuery query(QSqlDatabase::database("MyConnect"));
    query.prepare(QString("SELECT * FROM Users WHERE login = :login"));

    query.bindValue(":balance", balance);
    query.bindValue(":login", login);

    if(!query.exec()){
        qDebug() << "balance_failed";
    } else {
        while(query.next()) {
            QString balanceFromDB = query.value(4).toString();
            QString usernameFromDB = query.value(1).toString();

            if(usernameFromDB == login) {
                this->money = balanceFromDB;
                ui->userbalance->setText(balanceFromDB);
            } else {
                qDebug() << "balance failed";
            }
        }
    }
}

void HiLo::on_Higher_card_Button_clicked()
{
    int tmp_index = index;
    double tmp_high_coef = high_coeficient;
    ChangeTheCard();
    if(index > tmp_index)
    {
        if(tmp_high_coef <= 2)
            tmp_high_coef -= 1;
        cards_in_row = QString::number(cards_in_row.toInt() + 1);
        Total_coeficient = QString::number(Total_coeficient.toDouble() + tmp_high_coef);
        ui->coeficient_label->setText(Total_coeficient);
        ui->count_of_cards_label->setText(cards_in_row);
        QString possible_win = QString::number(Total_coeficient.toDouble() * stavka.toDouble());
        ui->Take_Cash->setText("Забрати "+possible_win+"");
    } else {
        cards_in_row = QString::number(0);
        Total_coeficient = QString::number(1.0);
        ui->coeficient_label->setText(Total_coeficient);
        ui->count_of_cards_label->setText(cards_in_row);
        ui->Take_Cash->setText("Забрати");
        ui->userbalance->setText(money);
        ui->play_button->raise();
        ui->Lower_Card_Button->lower();
        ui->Higher_card_Button->lower();
        ui->label->lower();
        ui->Take_Cash->lower();
        is_started = false;
    }
}


void HiLo::on_Lower_Card_Button_clicked()
{
    int tmp_index = index;
    double tmp_low_coef = low_coeficient;
    ChangeTheCard();
    if(index < tmp_index)
    {
        if(tmp_low_coef <= 2)
            tmp_low_coef -= 1;
        cards_in_row = QString::number(cards_in_row.toInt() + 1);
        Total_coeficient = QString::number(Total_coeficient.toDouble() + tmp_low_coef);
        ui->coeficient_label->setText(Total_coeficient);
        ui->count_of_cards_label->setText(cards_in_row);
        QString possible_win = QString::number(Total_coeficient.toDouble() * stavka.toDouble());
        ui->Take_Cash->setText("Забрати "+possible_win+"");
    } else {
        cards_in_row = QString::number(0);
        Total_coeficient = QString::number(1.0);
        ui->coeficient_label->setText(Total_coeficient);
        ui->count_of_cards_label->setText(cards_in_row);
        ui->userbalance->setText(money);
        ui->Take_Cash->setText("Забрати");
        ui->play_button->raise();
        ui->Lower_Card_Button->lower();
        ui->Higher_card_Button->lower();
        ui->label->lower();
        ui->Take_Cash->lower();
        is_started = false;
    }
}

void HiLo::on_minus_button_clicked()
{
    if(is_started == true)
        return;
    ui->minus_button->lower();
    ui->plus_button->raise();
    is_plus = false;
}


void HiLo::on_plus_button_clicked()
{
    if(is_started == true)
        return;
    ui->plus_button->lower();
    ui->minus_button->raise();
    is_plus = true;
}


void HiLo::on__0_1_Button_clicked()
{
    if(is_started == true)
        return;
    if(is_plus == true)
    {
        if (stavka.toDouble() <= this->money.toDouble() - 0.1)
        {
            stavka = QString::number(stavka.toDouble() + 0.1);
            ui->summa_stavky->setText(stavka);
        }
    } else {
        if (stavka.toDouble() >= 0.1)
        {
            stavka = QString::number(stavka.toDouble() - 0.1);
            ui->summa_stavky->setText(stavka);
        }
    }
}


void HiLo::on__0_5_Button_clicked()
{
    if(is_started == true)
        return;
    if(is_plus == true)
    {
        if (stavka.toDouble() <= this->money.toDouble() - 0.5)
        {
            stavka = QString::number(stavka.toDouble() + 0.5);
            ui->summa_stavky->setText(stavka);
        }
    } else {
        if (stavka.toDouble() >= 0.5)
        {
            stavka = QString::number(stavka.toDouble() - 0.5);
            ui->summa_stavky->setText(stavka);
        }
    }
}


void HiLo::on__1_Button_clicked()
{
    if(is_started == true)
        return;
    if(is_plus == true)
    {
        if (stavka.toDouble() <= this->money.toDouble() - 1)
        {
            stavka = QString::number(stavka.toDouble() + 1);
            ui->summa_stavky->setText(stavka);
        }
    } else {
        if (stavka.toDouble() >= 1)
        {
            stavka = QString::number(stavka.toDouble() - 1);
            ui->summa_stavky->setText(stavka);
        }
    }
}


void HiLo::on__5_Button_clicked()
{
    if(is_started == true)
        return;
    if(is_plus == true)
    {
        if (stavka.toDouble() <= this->money.toDouble() - 5)
        {
            stavka = QString::number(stavka.toDouble() + 5);
            ui->summa_stavky->setText(stavka);
        }
    } else {
        if (stavka.toDouble() >= 5)
        {
            stavka = QString::number(stavka.toDouble() - 5);
            ui->summa_stavky->setText(stavka);
        }
    }
}


void HiLo::on__20_Button_clicked()
{
    if(is_started == true)
        return;
    if(is_plus == true)
    {
        if (stavka.toDouble() <= this->money.toDouble() - 20)
        {
            stavka = QString::number(stavka.toDouble() + 20);
            ui->summa_stavky->setText(stavka);
        }
    } else {
        if (stavka.toDouble() >= 20)
        {
            stavka = QString::number(stavka.toDouble() - 20);
            ui->summa_stavky->setText(stavka);
        }
    }
}


void HiLo::on__100_Button_clicked()
{
    if(is_started == true)
        return;
    if(is_plus == true)
    {
        if (stavka.toDouble() <= this->money.toDouble() - 100)
        {
            stavka = QString::number(stavka.toDouble() + 100);
            ui->summa_stavky->setText(stavka);
        }
    } else {
        if (stavka.toDouble() >= 100)
        {
            stavka = QString::number(stavka.toDouble() - 100);
            ui->summa_stavky->setText(stavka);
        }
    }
}


void HiLo::on__500_Button_clicked()
{
    if(is_started == true)
        return;
    if(is_plus == true)
    {
        if (stavka.toDouble() <= this->money.toDouble() - 500)
        {
            stavka = QString::number(stavka.toDouble() + 500);
            ui->summa_stavky->setText(stavka);
        }
    } else {
        if (stavka.toDouble() >= 500)
        {
            stavka = QString::number(stavka.toDouble() - 500);
            ui->summa_stavky->setText(stavka);
        }
    }
}


void HiLo::on_X2_Button_clicked()
{
    if(is_started == true)
        return;
    if ((stavka.toDouble() * 2.0) <= this->money.toDouble())
    {
        stavka = QString::number(stavka.toDouble() * 2.0);
        ui->summa_stavky->setText(stavka);
    }
}


void HiLo::on_half_button_clicked()
{
    if(is_started == true)
        return;
    if (stavka.toDouble() >= 2)
    {
        stavka = QString::number(stavka.toDouble() / 2.0);
        ui->summa_stavky->setText(stavka);
    }
}


void HiLo::on_Change_card_clicked()
{
    if(is_started == true)
        return;
    ChangeTheCard();
}

double HiLo::MakeLowCoeficient(int current_index)
{
    int tmp = 12 - current_index;
    switch (tmp)
    {
    case 0:
        return 1.2;
       break;
    case 1:
        return 1.4;
        break;
    case 2:
        return 1.6;
        break;
    case 3:
        return 1.8;
        break;
    case 4:
        return 2.0;
        break;
    case 5:
        return 2.5;
        break;
    case 6:
        return 3.0;
        break;
    case 7:
        return 3.5;
        break;
    case 8:
        return 4;
        break;
    case 9:
        return 5;
        break;
    case 10:
        return 6;
        break;
    case 11:
        return 8;
        break;
    case 12:
        return 10;
        break;
    }
    return 0;
}

double HiLo::MakeHighCoeficient(int current_index)
{
    int tmp = 12 - current_index;
    switch (tmp)
    {
    case 0:
        return 10;
       break;
    case 1:
        return 8;
        break;
    case 2:
        return 6;
        break;
    case 3:
        return 5;
        break;
    case 4:
        return 4;
        break;
    case 5:
        return 3.5;
        break;
    case 6:
        return 3.0;
        break;
    case 7:
        return 2.5;
        break;
    case 8:
        return 2;
        break;
    case 9:
        return 1.8;
        break;
    case 10:
        return 1.6;
        break;
    case 11:
        return 1.4;
        break;
    case 12:
        return 1.2;
        break;
    }
    return 0;
}


void HiLo::on_Take_Cash_clicked()
{
    money = QString::number(money.toDouble() + (stavka.toDouble() * Total_coeficient.toDouble()));

    int result = 1;
    QString s = "SELECT login AND balance from caligula_users.Users;";
    QSqlQuery query = database.query_func(s);
    while(query.next()){
    }
    if(result == 1){

        QString s = "UPDATE caligula_users.Users SET balance= " +money+ " WHERE login = " +login+ ";";
        QSqlQuery query = database.query_func(s);
    }
    cards_in_row = QString::number(0);
    Total_coeficient = QString::number(1.0);
    ui->coeficient_label->setText(Total_coeficient);
    ui->count_of_cards_label->setText(cards_in_row);
    ChangeTheCard();

    ui->play_button->raise();
    ui->Lower_Card_Button->lower();
    ui->Higher_card_Button->lower();
    ui->label->lower();
    ui->Take_Cash->lower();
    ui->userbalance->setText(money);
    is_started = false;
}


void HiLo::on_play_button_clicked()
{
    if(stavka.toDouble() < 1 || stavka.toDouble() > money.toDouble())
        return;
    is_started = true;

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
    ui->userbalance->setText(money);
    ui->play_button->lower();
    ui->Lower_Card_Button->raise();
    ui->Higher_card_Button->raise();
    ui->label->raise();
    ui->Take_Cash->raise();

}


void HiLo::on_info_clicked()
{
    QMessageBox::about(this, "Інформація", "HiLo - це різновид карткових азартних ігор, в якій для виграшу вам необхідно вгадати, чи буде наступна карта молодша або старша, ніж карта, яку гравець бачить перед собою. У грі використовується стандартна колода із п'ятдесяти двох карт. Колода карток тасується перед кожною роздачею.");
}

