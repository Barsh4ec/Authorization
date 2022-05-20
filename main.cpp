#include "authorization.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Authorization w;
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR","1");
    w.resize(600, 700);
    w.show();
    return a.exec();
}
