#include "crash.h"
#include "ui_crash.h"

Crash::Crash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Crash)
{
    ui->setupUi(this);
    setWindowTitle("Crash");
    this->resize(1040, 700);
}

Crash::~Crash()
{
    delete ui;
}

void Crash::on_BackToMain_clicked()
{
    this->close();
    emit crashWindow();
}

