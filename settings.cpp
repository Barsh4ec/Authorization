#include "settings.h"
#include "ui_settings.h"
#include <QDebug>
#include <fstream>
#include <QFile>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QCoreApplication>

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
}

void Settings::Write(QString path, QByteArray a)
{
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "cannot find file!";
        qDebug() << file.errorString();
    } else {
        if(path == "lang_config.txt")
        {
            file.write(a);
        }
        if(path == "theme_config.txt")
        {
            file.write(a);
        }
    }
    file.close();
}

void Settings::on_lang_button_clicked()
{
    int index = ui->Change_lang->currentIndex();
    QString path = "lang_config.txt";
    QFile file(path);
    QByteArray currentlang;

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "cannot find file!";
        qDebug() << file.errorString();
    } else {
        if(index == 0) //// english
        {
            currentlang = file.readAll();
            if(currentlang == QByteArray("eng"))
            {
                ui->information->setText("Ви вже використовуєте англійську!");
            } else {
                Write(path, QByteArray("eng"));
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Виберіть дію!", "Для зміни мови необхідно перезапустити програму! Чи бажаєте ви перезапустити програму зараз?",
                                      QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    qApp->quit();
                    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
                }else {
                    return;
                }
            }
        }
        if(index == 1) //// ukrainian
        {
            currentlang = file.readAll();
            if(currentlang == QByteArray("ukr"))
            {
                ui->information->setText("Ви вже використовуєте українську!");
            } else {
                Write(path, QByteArray("ukr"));
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Виберіть дію!", "Для зміни мови необхідно перезапустити програму! Чи бажаєте ви перезапустити програму зараз?",
                                      QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    qApp->quit();
                    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
                }else {
                    return;
                }
            }
        }
    }
    file.close();
}


void Settings::on_theme_button_clicked()
{
    int index = ui->Change_theme->currentIndex();
    QString path = "theme_config.txt";
    QFile file(path);
    QByteArray currentTheme;

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "cannot find file!";
        qDebug() << file.errorString();
    } else {
        if(index == 0) //// Темна тема
        {
            currentTheme = file.readAll();
            if(currentTheme == QByteArray("black"))
            {
                ui->information->setText("Ви вже використовуєте темну тему!");
            } else {
                Write(path, QByteArray("black"));
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Виберіть дію!", "Для зміни теми необхідно перезапустити програму! Чи бажаєте ви перезапустити програму зараз?",
                                      QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    qApp->quit();
                    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
                }else {
                    return;
                }
            }
        }
        if(index == 1) //// Світла тема
        {
            currentTheme = file.readAll();
            if(currentTheme == QByteArray("white"))
            {
                ui->information->setText("Ви вже використовуєте світлу тему!");
            } else {
                Write(path, QByteArray("white"));
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Виберіть дію!", "Для зміни теми необхідно перезапустити програму! Чи бажаєте ви перезапустити програму зараз?",
                                      QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    qApp->quit();
                    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
                }else {
                    return;
                }
            }
        }
    }
    file.close();
}

