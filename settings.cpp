#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_BackToMain_clicked()
{
    this->close();
    emit SettingsWindow();
}

void Settings::slot(QString a)
{
    login = a;
    qDebug() << login;
}
