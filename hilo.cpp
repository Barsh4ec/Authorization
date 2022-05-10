#include "hilo.h"
#include "ui_hilo.h"

HiLo::HiLo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HiLo)
{
    ui->setupUi(this);
    setWindowTitle("HiLo");
    this->resize(1040, 700);
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

void HiLo::slot(QString a)
{
    login = a;
    qDebug() << login;
}
