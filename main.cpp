#include "authorization.h"

#include <QApplication>
#include <QTranslator>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile stylesheetFile(":/black_theme.qss");
    //QFile stylesheetFile(":/light_theme.qss");
    stylesheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(stylesheetFile.readAll());
    a.setStyleSheet(styleSheet);

    QTranslator t;
    //t.load(":/lang_uk.qm");
    t.load(":/lang_en.qm");
    a.installTranslator(&t);


    Authorization w;
    w.resize(600, 700);
    w.show();
    return a.exec();
}
