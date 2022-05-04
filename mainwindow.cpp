#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString login, QString password) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Caligula's Palace");
    this->resize(1040, 800);

    roulette = new Roulette();
    connect(roulette, &Roulette::fWindow, this, &MainWindow::show);

    slotte = new Slots();
    connect(slotte, &Slots::slotsWindow, this, &MainWindow::show);

    blackjack = new BlackJack();
    connect(blackjack, &BlackJack::bjWindow, this, &MainWindow::show);

    hilo = new HiLo();
    connect(hilo, &HiLo::HiLoWindow, this, &MainWindow::show);

    crash = new Crash();
    connect(crash, &Crash::crashWindow, this, &MainWindow::show);

    minesweeper = new Minesweeper();
    connect(minesweeper, &Minesweeper::minesWindow, this, &MainWindow::show);

    addmoney = new AddMoney();
    connect(addmoney, &AddMoney::addMWindow, this, &AddMoney::show);

    accsett = new AccountSettings();
    connect(accsett, &AccountSettings::AccountSettWindow, this, &AccountSettings::show);

    settings = new Settings();
    connect(settings, &Settings::SettingsWindow, this, &Settings::show);

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
                ui->userbalance->setText(balanceFromDB);

            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RouletteButton_clicked()
{
    roulette->show();
    this->close();
}


void MainWindow::on_slotsButton_clicked()
{
    slotte->show();
    this->close();
}


void MainWindow::on_BJButton_clicked()
{
    blackjack->show();
    this->close();
}


void MainWindow::on_HiLoButton_clicked()
{
    hilo->show();
    this->close();
}


void MainWindow::on_CrashButton_clicked()
{
    crash->show();
    this->close();
}


void MainWindow::on_MinesButton_clicked()
{
    minesweeper->show();
    this->close();
}


void MainWindow::on_PopovnytyRachunok_clicked()
{
    addmoney->show();
    this->close();
}


void MainWindow::on_AccountSettings_clicked()
{
    accsett->show();
    this->close();
}


void MainWindow::on_SettingsButon_clicked()
{
    settings->show();
    this->close();
}

