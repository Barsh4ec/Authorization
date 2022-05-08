#include "accountsettings.h"
#include "ui_accountsettings.h"
AccountSettings::AccountSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountSettings)
{
    ui->setupUi(this);
    database.db_connect();

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


void AccountSettings::on_button_change_name_clicked()
{
    QSqlQuery query(QSqlDatabase::database("db_con"));


}

