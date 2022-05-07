#include "accountsettings.h"
#include "ui_accountsettings.h"

AccountSettings::AccountSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountSettings)
{
    ui->setupUi(this);
}

AccountSettings::~AccountSettings()
{
    delete ui;
}



void AccountSettings::on_BackToMain_clicked()
{
    this->close();
    emit AccountSettWindow();
}

