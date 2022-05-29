#include "authorization.h"

#include <QApplication>
#include <QTranslator>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ////////////////////////////////////////////////// Вибір теми
    QFile theme_file("theme_config.txt");
    QByteArray currentTheme;
    if(!theme_file.open(QIODevice::ReadOnly))
        {
            qDebug() << "cannot find file!";
            qDebug() << theme_file.errorString();
        } else {
            currentTheme = theme_file.readAll();
            if(currentTheme == "black") //// english
            {
                QFile stylesheetFile(":/black_theme.qss");
                stylesheetFile.open(QFile::ReadOnly);
                QString styleSheet = QLatin1String(stylesheetFile.readAll());
                a.setStyleSheet(styleSheet);
            }
            if(currentTheme == "white") //// english
            {
                QFile stylesheetFile(":/light_theme.qss");
                stylesheetFile.open(QFile::ReadOnly);
                QString styleSheet = QLatin1String(stylesheetFile.readAll());
                a.setStyleSheet(styleSheet);
            }
    }
    theme_file.close();

    /////////////////////////////////////////////////// Вибір мови
    QTranslator t;
    QFile lang_file("lang_config.txt");
    QByteArray currentlang;
    if(!lang_file.open(QIODevice::ReadOnly))
        {
            qDebug() << "cannot find file!";
            qDebug() << lang_file.errorString();
        } else {
            currentlang = lang_file.readAll();
            if(currentlang == "eng") //// english
            {
                t.load(":/lang_en.qm");
                a.installTranslator(&t);
            }
            if(currentlang == "ukr") //// english
            {
                t.load(":/lang_uk.qm");
                a.installTranslator(&t);
            }
    }
    lang_file.close();


    Authorization w;
    w.resize(600, 700);
    w.show();
    return a.exec();
}
