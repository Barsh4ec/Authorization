#ifndef ROULETTE_H
#define ROULETTE_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "db.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#define PI 3.14159265358979323846

class PixmapItem : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal rotate READ rotation WRITE setRot/*ation*/)
public:
    PixmapItem(const QPixmap &pix) : QGraphicsPixmapItem(pix){

        // Set point rotation
        crX = qreal(pixmap().width())  / 2.0;
        crY = qreal(pixmap().height()) / 2.0;
        // Radius rotation
        crR = sqrt(crX*crX + crY*crY);


        // Adjust point from scene
        crX = qreal(pixmap().width())  / 2.0F - 0.0F;
        crY = qreal(pixmap().height()) / 2.0F - 5.0F;
    }

    inline
    void setRot(qreal a)
    {
        qreal dxc = cos(((a+225.0F) / 360.0F) * 2 * PI) * crR + crX;
        qreal dyc = sin(((a+225.0F) / 360.0F) * 2 * PI) * crR + crY;

        this->setPos(dxc, dyc);
        setRotation(a);
    }


private:
    qreal crR; // radius
    qreal crX; // point rotation x
    qreal crY; // point rotation y
};


namespace Ui {
class Roulette;
}

class Roulette : public QWidget
{
    Q_OBJECT

public:
    explicit Roulette(QWidget *parent = nullptr);
    ~Roulette();
    int tmp2 = 0;
    int tmp1 = 0;
    int position = 0;
    QString login;
    QString password;
    QString stavka = "1";
    QString plus = "1";
    QString money;
    QString mas[15][2] = { {"green", "0"}, {"red", "1"}, {"black", "8"}, {"red", "2"}, {"black", "9"}, {"red", "3"}, {"black", "10"}, {"red", "4"},
                           {"black", "11"}, {"red", "5"}, {"black", "12"}, {"red", "6"}, {"black", "13"}, {"red", "7"}, {"black", "14"} };
    QString history[8][2] = { {"#544475", ""}, {"#544475", ""}, {"#544475", ""}, {"#544475", ""}, {"#544475", ""}, {"#544475", ""}, {"#544475", ""}, {"#544475", ""} };
    void Speen_Wheel(int);
    int MakeTime(int, int);
    void Timer(int);
    bool start_stop = false;

signals:
    void fWindow();

private slots:
    void on_BackToMain_clicked();

    void on_plus_value_button_clicked();

    void on_minus_value_button_clicked();

    void on_max_value_button_clicked();

    void on_half_value_button_clicked();

    void on_x2_value_button_clicked();

    void on_min_value_button_clicked();

    void on_bet_on_red_clicked();

    void on_bet_on_black_clicked();

    void on_bet_on_green_clicked();

    void on_info_clicked();

    void TimerSlot();
public slots:
    void slot(QString a, QString b);

public Q_SLOTS:
    inline void start(){ m_anim->start(); }
    inline void stop() { m_anim->stop();  }

private:
    void ChangeHistory(QString, QString);
    db database;
    Ui::Roulette *ui;
    Roulette *roulette;
    QPixmap pixmap;
    QPropertyAnimation *m_anim;
    PixmapItem *an_pix;
    PixmapItem *pointer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    int time;
    int tmp_time = 0;

};

#endif // ROULETTE_H
