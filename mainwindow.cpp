#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
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

