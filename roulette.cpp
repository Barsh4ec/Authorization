#include "roulette.h"
#include "ui_roulette.h"

Roulette::Roulette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roulette)
{
    ui->setupUi(this);
    setWindowTitle("Roulette");
    this->resize(1040, 700);
}

Roulette::~Roulette()
{
    delete ui;
}

void Roulette::on_BakToMain1_clicked()
{
    this->close();
    emit fWindow();
}

void Roulette::slot(QString a)
{
    login = a;
    qDebug() << login;
}

