#include "blackjack.h"
#include "ui_blackjack.h"

BlackJack::BlackJack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlackJack)
{
    ui->setupUi(this);
    setWindowTitle("BlackJack");
    this->resize(1040, 700);
}

BlackJack::~BlackJack()
{
    delete ui;
}

void BlackJack::on_BackToMain_clicked()
{
    this->close();
    emit bjWindow();
}

void BlackJack::slot(QString a)
{
    login = a;
    qDebug() << login;
}
