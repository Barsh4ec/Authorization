#include "blackjack.h"
#include "ui_blackjack.h"
#include <QTimer>
#include <QMessageBox>

BlackJack::BlackJack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlackJack)
{
    ui->setupUi(this);
    setWindowTitle(QObject::tr("BlackJack"));
    this->resize(1000, 700);
    ui->Add->lower();
    ui->Stay->lower();
}

BlackJack::~BlackJack()
{
    delete ui;
}
static int randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}
int BlackJack::ChangeDealerCard()
{
    int index = randomBetween(0, 12);
    int type_of_card = randomBetween(1, 4);
    switch(dealer_step)
    {
    case(0):
        switch(type_of_card)
        {
        case(1):
            ui->Dealer_Card_Label1->setStyleSheet("background: url("+dealer_bubna[index]+");");
            break;
        case(2):
            ui->Dealer_Card_Label1->setStyleSheet("background: url("+dealer_cherva[index]+");");
            break;
        case(3):
            ui->Dealer_Card_Label1->setStyleSheet("background: url("+dealer_pika[index]+");");
            break;
        case(4):
            ui->Dealer_Card_Label1->setStyleSheet("background: url("+dealer_hresta[index]+");");
            break;
        }
        break;
    case(1):
        switch(type_of_card)
        {
        case(1):
            ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_bubna[index]+");");
            break;
        case(2):
            ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_cherva[index]+");");
            break;
        case(3):
            ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_pika[index]+");");
            break;
        case(4):
            ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_hresta[index]+");");
            break;
        }
        break;
    case(2):
        switch(type_of_card)
        {
        case(1):
            ui->Dealer_Card_Label3->setStyleSheet("background: url("+dealer_bubna[index]+");");
            break;
        case(2):
            ui->Dealer_Card_Label3->setStyleSheet("background: url("+dealer_cherva[index]+");");
            break;
        case(3):
            ui->Dealer_Card_Label3->setStyleSheet("background: url("+dealer_pika[index]+");");
            break;
        case(4):
            ui->Dealer_Card_Label3->setStyleSheet("background: url("+dealer_hresta[index]+");");
            break;
        }
        break;
    case(3):
        switch(type_of_card)
        {
        case(1):
            ui->Dealer_Card_Label4->setStyleSheet("background: url("+dealer_bubna[index]+");");
            break;
        case(2):
            ui->Dealer_Card_Label4->setStyleSheet("background: url("+dealer_cherva[index]+");");
            break;
        case(3):
            ui->Dealer_Card_Label4->setStyleSheet("background: url("+dealer_pika[index]+");");
            break;
        case(4):
            ui->Dealer_Card_Label4->setStyleSheet("background: url("+dealer_hresta[index]+");");
            break;
        }
        break;
    case(4):
        switch(type_of_card)
        {
        case(1):
            ui->Dealer_Card_Label5->setStyleSheet("background: url("+dealer_bubna[index]+");");
            break;
        case(2):
            ui->Dealer_Card_Label5->setStyleSheet("background: url("+dealer_cherva[index]+");");
            break;
        case(3):
            ui->Dealer_Card_Label5->setStyleSheet("background: url("+dealer_pika[index]+");");
            break;
        case(4):
            ui->Dealer_Card_Label5->setStyleSheet("background: url("+dealer_hresta[index]+");");
            break;
        }
    }

    return index;
}

int BlackJack::ChangePlayerCard()
{
    int index = randomBetween(0, 12);
    int type_of_card = randomBetween(1, 4);
    switch(player_step)
    {
    case(0):
        switch(type_of_card)
        {
        case(1):
            ui->First_Card_Label->setStyleSheet("background: url("+bubna[index]+");");
            break;
        case(2):
            ui->First_Card_Label->setStyleSheet("background: url("+cherva[index]+");");
            break;
        case(3):
            ui->First_Card_Label->setStyleSheet("background: url("+pika[index]+");");
            break;
        case(4):
            ui->First_Card_Label->setStyleSheet("background: url("+hresta[index]+");");
            break;
        }
        break;
    case(1):
        switch(type_of_card)
        {
        case(1):
            ui->Second_Card_Label->setStyleSheet("background: url("+bubna[index]+");");
            break;
        case(2):
            ui->Second_Card_Label->setStyleSheet("background: url("+cherva[index]+");");
            break;
        case(3):
            ui->Second_Card_Label->setStyleSheet("background: url("+pika[index]+");");
            break;
        case(4):
            ui->Second_Card_Label->setStyleSheet("background: url("+hresta[index]+");");
            break;
        }
        break;
    case(2):
        switch(type_of_card)
        {
        case(1):
            ui->Third_Card_Label->setStyleSheet("background: url("+bubna[index]+");");
            break;
        case(2):
            ui->Third_Card_Label->setStyleSheet("background: url("+cherva[index]+");");
            break;
        case(3):
            ui->Third_Card_Label->setStyleSheet("background: url("+pika[index]+");");
            break;
        case(4):
            ui->Third_Card_Label->setStyleSheet("background: url("+hresta[index]+");");
            break;
        }
        break;
    case(3):
        switch(type_of_card)
        {
        case(1):
            ui->Fourth_Card_Label->setStyleSheet("background: url("+bubna[index]+");");
            break;
        case(2):
            ui->Fourth_Card_Label->setStyleSheet("background: url("+cherva[index]+");");
            break;
        case(3):
            ui->Fourth_Card_Label->setStyleSheet("background: url("+pika[index]+");");
            break;
        case(4):
            ui->Fourth_Card_Label->setStyleSheet("background: url("+hresta[index]+");");
            break;
        }
        break;
    case(4):
        switch(type_of_card)
        {
        case(1):
            ui->Fiveth_Card_Label->setStyleSheet("background: url("+bubna[index]+");");
            break;
        case(2):
            ui->Fiveth_Card_Label->setStyleSheet("background: url("+cherva[index]+");");
            break;
        case(3):
            ui->Fiveth_Card_Label->setStyleSheet("background: url("+pika[index]+");");
            break;
        case(4):
            ui->Fiveth_Card_Label->setStyleSheet("background: url("+hresta[index]+");");
            break;
        }
        break;
    }
    return index;
}

void BlackJack::on_BackToMain_clicked()
{
    this->close();
    emit bjWindow();
}

void BlackJack::slot(QString a)
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

void BlackJack::on_StartGame_clicked()
{
    stavka = ui->summa_stavky->text();
    if ((stavka.toDouble()) > this->money.toDouble())
    {
        return;
    }
    if ((stavka.toDouble()) <= 0)
    {
        return;
    }
    ui->Result_label->setText("");
    is_started = true;
    ui->StartGame->lower();
    ui->Add->raise();
    ui->Stay->raise();

    player_card = ChangePlayerCard();
    int tmp_score = Make_score(player_card);
    player_score = QString::number(tmp_score);
    ui->player_score_label->setText(player_score);
    player_step++;
    Timer(1000);

    dealer_card = ChangeDealerCard();
    tmp_score = Make_score(dealer_card);
    dealer_score = QString::number(tmp_score);
    ui->dealer_score_label->setText(dealer_score);
    dealer_step++;
    Timer(1000);


    player_card = ChangePlayerCard();
    tmp_score = Make_score(player_card);
    player_score = QString::number(tmp_score + player_score.toInt());
    ui->player_score_label->setText(player_score);
    player_step++;
    Timer(1000);

    dealer_card = ChangeDealerCard();
    ui->Dealer_Card_Label2->setStyleSheet("background: url(:/resources/Much_Smaller_Cards/back_of_card.png)");
    dealer_step++;
    Timer(1000);
    is_started = false;
}


void BlackJack::on_Stay_clicked()
{
    if(is_started == true)
        return;
    is_started = true;
    int tmp_score = 0;
    if(player_score.toInt() > 21)
    {
        ui->Result_label->setText("Dealer Wins!");
        Stop_Game();
        TakeMoney();
        return;
    }
    if(dealer_score.toInt() < 19)
    {
        if(Dealer_stop == false)
        {
            if(dealer_step == 2)
            {
                tmp_score = Make_score(dealer_card);
                dealer_score = QString::number(tmp_score + dealer_score.toInt());
                ui->dealer_score_label->setText(dealer_score);
                dealer_step++;
                int type_of_card = randomBetween(1, 4);
                switch(type_of_card)
                {
                case(1):
                    ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_bubna[dealer_card]+");");
                    break;
                case(2):
                    ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_cherva[dealer_card]+");");
                    break;
                case(3):
                    ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_pika[dealer_card]+");");
                    break;
                case(4):
                    ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_hresta[dealer_card]+");");
                    break;
                }
                Timer(1000);
            }

            if(dealer_score.toInt() < 16)
            {
                dealer_card = ChangeDealerCard();
                tmp_score = Make_score(dealer_card);
                dealer_score = QString::number(dealer_score.toInt() + tmp_score);
                dealer_step++;
                ui->dealer_score_label->setText(dealer_score);
                Timer(1000);
            }
            if(dealer_score.toInt() >= 18 && dealer_score.toInt() < 19)
            {
                int rand = randomBetween(0,100);
                if(rand %2 == 1)
                {
                    dealer_card = ChangeDealerCard();
                    tmp_score = Make_score(dealer_card);
                    dealer_score = QString::number(dealer_score.toInt() + tmp_score);
                    ui->dealer_score_label->setText(dealer_score);
                    Timer(1000);
                }
                Dealer_stop = true;
            }
            if(dealer_score.toInt() == 21)
            {
                ui->Result_label->setText("Dealer Wins!");
                Stop_Game();
                TakeMoney();
                return;
            }
        }
    }

    if(dealer_score.toInt() >= 19 && player_score.toInt() < 19)
    {
        ui->Result_label->setText("Dealer Wins!");
        Stop_Game();
        TakeMoney();
        return;
    }
    if(dealer_score.toInt() > 21 && player_score.toInt() < 21)
    {
        ui->Result_label->setText("Player Wins!");
        Stop_Game();
        AddMoney();
        return;
    }
    if(dealer_score.toInt() < 18)
    {
        dealer_card = ChangeDealerCard();
        tmp_score = Make_score(dealer_card);
        dealer_score = QString::number(dealer_score.toInt() + tmp_score);
        ui->dealer_score_label->setText(dealer_score);
        dealer_step++;
        Timer(1000);
    }
    if(player_score.toInt() < 21 && dealer_score.toInt() == 21)
    {
        ui->Result_label->setText("Dealer Wins!");
        Stop_Game();
        TakeMoney();
        return;
    }
    if(dealer_score.toInt() == 19 && player_score.toInt() == 18)
    {
        ui->Result_label->setText("Dealer Wins!");
        Stop_Game();
        TakeMoney();
        return;
    }
    if(dealer_score.toInt() == 19 && player_score.toInt() == 20)
    {
        ui->Result_label->setText("Player Wins!");
        Stop_Game();
        AddMoney();
        return;
    }
    if(player_score.toInt() > 21 && dealer_score.toInt() == 21)
    {
        ui->Result_label->setText("Dealer Wins!");
        Stop_Game();
        TakeMoney();
        return;
    }
    if(player_score.toInt() == 21 && dealer_score.toInt() < 21)
    {
        ui->Result_label->setText("Player Wins!");
        Stop_Game();
        AddMoney();
        return;
    }
    if(player_score.toInt() > 21 && dealer_score.toInt() > 21)
    {
        ui->Result_label->setText("Player Wins!");
        Stop_Game();
        AddMoney();
        return;
    }
    if(player_score.toInt() == 21 && dealer_score.toInt() > 21)
    {
        ui->Result_label->setText("Player Wins!");
        Stop_Game();
        AddMoney();
        return;
    }
    if(player_score.toInt() == dealer_score.toInt())
    {
        ui->Result_label->setText("Draw!");
        Stop_Game();
        return;
    }
    if(player_score.toInt() > 21 && dealer_score.toInt() < 21)
    {
        ui->Result_label->setText("Dealer Wins!");
        Stop_Game();
        TakeMoney();
        return;
    }
    if(player_score.toInt() < 21 && dealer_score.toInt() > 21)
    {
        ui->Result_label->setText("Player Wins!");
        Stop_Game();
        AddMoney();
        return;
    }
    if(player_score.toInt() == 19 && dealer_score.toInt() == 20)
    {
        ui->Result_label->setText("Dealer Wins!");
        Stop_Game();
        TakeMoney();
        return;
    }
    is_started = false;
    if(dealer_score.toInt() > 21)
    {
        ui->Result_label->setText("Player Wins!");
        Stop_Game();
        AddMoney();
        return;
    }
}


void BlackJack::on_Add_clicked()
{
    if(is_started == true)
        return;
    is_started = true;

    player_card = ChangePlayerCard();
    int tmp_score = Make_score(player_card);
    player_score = QString::number(player_score.toInt() + tmp_score);
    ui->player_score_label->setText(player_score);
    Timer(1000);
    ////////////////////////////////////

    if(Dealer_stop == false)
    {
        if(dealer_step == 2)
        {
            tmp_score = Make_score(dealer_card);
            dealer_score = QString::number(tmp_score + dealer_score.toInt());
            ui->dealer_score_label->setText(dealer_score);
            int type_of_card = randomBetween(1, 4);
            switch(type_of_card)
            {
            case(1):
                ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_bubna[dealer_card]+");");
                break;
            case(2):
                ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_cherva[dealer_card]+");");
                break;
            case(3):
                ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_pika[dealer_card]+");");
                break;
            case(4):
                ui->Dealer_Card_Label2->setStyleSheet("background: url("+dealer_hresta[dealer_card]+");");
                break;
            }
            Timer(1000);
        }

        if(dealer_score.toInt() < 16)
        {
            dealer_card = ChangeDealerCard();
            tmp_score = Make_score(dealer_card);
            dealer_score = QString::number(dealer_score.toInt() + tmp_score);
            ui->dealer_score_label->setText(dealer_score);
            dealer_step++;
            Timer(1000);
        }
        if(dealer_score.toInt() > 16 && dealer_score.toInt() < 19)
        {
            int rand = randomBetween(0,100);
            if(rand %2 == 1)
            {
                dealer_card = ChangeDealerCard();
                tmp_score = Make_score(dealer_card);
                dealer_score = QString::number(dealer_score.toInt() + tmp_score);
                ui->dealer_score_label->setText(dealer_score);
                dealer_step++;
                Timer(1000);
            }
            Dealer_stop = true;
        }
        if(dealer_score.toInt() == 21)
        {
            ui->Result_label->setText("Dealer Wins!");
            Stop_Game();
            TakeMoney();
            return;
        }
        if(dealer_score.toInt() > 21 && player_score.toInt() < 21)
        {
            ui->Result_label->setText("Player Wins!");
            Stop_Game();
            AddMoney();
            return;
        }
    }

    if(player_score.toInt() <= 19)
    {
        is_started = false;
        player_step++;
        return;
    }
    if(player_score.toInt() >= 19)
    {
        if(dealer_score.toInt() < 18)
        {
            dealer_card = ChangeDealerCard();
            tmp_score = Make_score(dealer_card);
            dealer_score = QString::number(dealer_score.toInt() + tmp_score);
            ui->dealer_score_label->setText(dealer_score);
            dealer_step++;
            Timer(1000);
        }
        if(player_score.toInt() < 21 && dealer_score.toInt() == 21)
        {
            ui->Result_label->setText("Dealer Wins!");
            Stop_Game();
            TakeMoney();
            return;
        }
        if(player_score.toInt() > 21 && dealer_score.toInt() == 21)
        {
            ui->Result_label->setText("Dealer Wins!");
            Stop_Game();
            TakeMoney();
            return;
        }
        if(player_score.toInt() == 21 && dealer_score.toInt() < 21)
        {
            ui->Result_label->setText("Player Wins!");
            Stop_Game();
            AddMoney();
            return;
        }
        if(player_score.toInt() == 20 && dealer_score.toInt() == 19)
        {
            ui->Result_label->setText("Player Wins!");
            Stop_Game();
            AddMoney();
            return;
        }
        if(player_score.toInt() == 19 && dealer_score.toInt() == 20)
        {
            ui->Result_label->setText("Dealer Wins!");
            Stop_Game();
            TakeMoney();
            return;
        }
        if(player_score.toInt() > 21 && dealer_score.toInt() > 21)
        {
            ui->Result_label->setText("Draw!");
            Stop_Game();
            return;
        }
        if(player_score.toInt() == 21 && dealer_score.toInt() > 21)
        {
            ui->Result_label->setText("Player Wins!");
            Stop_Game();
            AddMoney();
            return;
        }
        if(player_score.toInt() == dealer_score.toInt())
        {
            ui->Result_label->setText("Draw!");
            Stop_Game();
            return;
        }
        if(player_score.toInt() > 21 && dealer_score.toInt() < 21)
        {
            ui->Result_label->setText("Dealer Wins!");
            Stop_Game();
            TakeMoney();
            return;
        }
        if(player_score.toInt() < 21 && dealer_score.toInt() > 21)
        {
            ui->Result_label->setText("Player Wins!");
            Stop_Game();
            AddMoney();
            return;
        }
    }
    if(dealer_score.toInt() > 21)
    {
        ui->Result_label->setText("Player Wins!");
        Stop_Game();
        AddMoney();
        return;
    }
    is_started = false;
}

int BlackJack::Make_score(int index)
{
    switch(index)
    {
    case(0):
        return 2;
        break;
    case(1):
        return 3;
        break;
    case(2):
        return 4;
        break;
    case(3):
        return 5;
        break;
    case(4):
        return 6;
        break;
    case(5):
        return 7;
        break;
    case(6):
        return 8;
        break;
    case(7):
        return 9;
        break;
    case(8):
        return 10;
        break;
    case(9):
        return 10;
        break;
    case(10):
        return 10;
        break;
    case(11):
        return 10;
        break;
    case(12):
        return 10;
        break;
    }
    return 0;
}

void BlackJack::Stop_Game()
{
    Timer(3000);
    player_step = 0;
    dealer_step = 0;
    player_score = "0";
    dealer_score = "0";
    player_card = 0;
    dealer_card = 0;
    ui->dealer_score_label->setText(dealer_score);
    ui->player_score_label->setText(player_score);
    ui->Add->lower();
    ui->Stay->lower();
    ui->StartGame->raise();
    ui->First_Card_Label->setStyleSheet("background:");
    ui->Second_Card_Label->setStyleSheet("background:");
    ui->Third_Card_Label->setStyleSheet("background:");
    ui->Fourth_Card_Label->setStyleSheet("background:");
    ui->Fiveth_Card_Label->setStyleSheet("background:");

    ui->Dealer_Card_Label1->setStyleSheet("background:");
    ui->Dealer_Card_Label2->setStyleSheet("background:");
    ui->Dealer_Card_Label3->setStyleSheet("background:");
    ui->Dealer_Card_Label4->setStyleSheet("background:");
    ui->Dealer_Card_Label5->setStyleSheet("background:");
    Dealer_stop = false;
    is_started = false;
}

void BlackJack::Timer(int a)
{
    QEventLoop q;
    QTimer t;
    t.setSingleShot(true);
    connect(&t, SIGNAL(timeout()), &q, SLOT(quit()));
    t.start(a); // 5s timeout
    q.exec();
}

void BlackJack::AddMoney()
{
    money = QString::number(money.toDouble() + stavka.toDouble());

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
}

void BlackJack::TakeMoney()
{
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
}

void BlackJack::on_info_clicked()
{
    QMessageBox::about(this, "Інформація", "Бле́кджек — популярна азартна карткова гра. Black Jack належить до банкових ігор, тобто до таких, де гравці б'ються не між собою — кожен з них грає проти банку. Блекджек — одна з небагатьох ігор в казино, де результат гри залежить не тільки від випадку, але й від здібностей і вміння гравця.");
}

