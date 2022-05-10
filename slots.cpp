#include "slots.h"
#include "ui_slots.h"

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

void Slots::slot(QString a)
{
    login = a;
    qDebug() << login;
}

