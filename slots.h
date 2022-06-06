#ifndef SLOTS_H
#define SLOTS_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "db.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
namespace Ui {
class Slots;
}

class Slots : public QWidget
{
    Q_OBJECT

public:
    QString login;
    QString password;
    int tmp2 = 0;
    int tmp1 = 0;
    QString stavka = "0";
    QString money;
    QString mas[8] ={":/resources/png/10.png",":/resources/png/Bar.png",":/resources/png/Cherry.png",":/resources/png/Crown.png",":/resources/png/Diamond.png",":/resources/png/lemon.png",":/resources/png/Seven.png",":/resources/png/Watermelon.png"};
    explicit Slots(QWidget *parent = nullptr);
     int randomBetween(int low, int high);
    ~Slots();
     void Timer(int);
     int RandomPicture1();
     int RandomPicture2();
     int RandomPicture3();

signals:
    void slotsWindow();

private slots:
    void on_BackToMain_clicked();

    void on_StartGame_clicked();



public slots:
    void slot(QString a, QString b);
    void RandomGenerate();

private:
    Ui::Slots *ui;
    db database;
};

#endif // SLOTS_H
