#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString login, QString password) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Caligula's Palace");
    this->resize(1040, 800);
    this->login = login;

    roulette = new Roulette();
    connect(roulette, &Roulette::fWindow, this, &MainWindow::show);
    connect(this, &MainWindow::roulettesignal, roulette, &Roulette::slot);

    slotte = new Slots();
    connect(slotte, &Slots::slotsWindow, this, &MainWindow::show);
    connect(this, &MainWindow::slotssignal, slotte, &Slots::slot);

    blackjack = new BlackJack();
    connect(blackjack, &BlackJack::bjWindow, this, &MainWindow::show);
    connect(this, &MainWindow::bjsignal, blackjack, &BlackJack::slot);

    hilo = new HiLo();
    connect(hilo, &HiLo::HiLoWindow, this, &MainWindow::show);
    connect(this, &MainWindow::hilosignal, hilo, &HiLo::slot);

    crash = new Crash();
    connect(crash, &Crash::crashWindow, this, &MainWindow::show);
    connect(this, &MainWindow::crashsignal, crash, &Crash::slot);

    minesweeper = new Minesweeper();
    connect(minesweeper, &Minesweeper::minesWindow, this, &MainWindow::show);
    connect(this, &MainWindow::minessignal, minesweeper, &Minesweeper::slot);

    addmoney = new AddMoney();
    connect(addmoney, &AddMoney::addMWindow, this, &AddMoney::show);
    connect(this, &MainWindow::addmsignal, addmoney, &AddMoney::slot);

    accsett = new AccountSettings();
    connect(accsett, &AccountSettings::AccountSettWindow, this, &AccountSettings::show);
    connect(this, &MainWindow::accsignal, accsett, &AccountSettings::slot);

    settings = new Settings();
    connect(settings, &Settings::SettingsWindow, this, &Settings::show);
    connect(this, &MainWindow::settsignal, settings, &Settings::slot);

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
    emit roulettesignal(login);
    roulette->show();
    this->close();
}


void MainWindow::on_slotsButton_clicked()
{
    emit slotssignal(login);
    slotte->show();
    this->close();
}


void MainWindow::on_BJButton_clicked()
{
    emit bjsignal(login);
    blackjack->show();
    this->close();
}


void MainWindow::on_HiLoButton_clicked()
{
    emit hilosignal(login);
    hilo->show();
    this->close();
}


void MainWindow::on_CrashButton_clicked()
{
    emit crashsignal(login);
    crash->show();
    this->close();
}


void MainWindow::on_MinesButton_clicked()
{
    emit minessignal(login);
    minesweeper->show();
    this->close();
}


void MainWindow::on_PopovnytyRachunok_clicked()
{
    emit addmsignal(login);
    addmoney->show();
    this->close();
}


void MainWindow::on_AccountSettings_clicked()
{
    emit accsignal(login);
    accsett->show();
    this->close();
}


void MainWindow::on_SettingsButon_clicked()
{
    emit settsignal(login);
    settings->show();
    this->close();
}

