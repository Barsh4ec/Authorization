#ifndef CRASH_H
#define CRASH_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "db.h"
#include <QTimer>

namespace Ui {
class Crash;
}

class Crash : public QWidget
{
    Q_OBJECT

public:
    explicit Crash(QWidget *parent = nullptr);
    ~Crash();
    QString login;
    QString password;
    QString stavka = "1";
    QString coeficient = "1";
    QString plus = "1";
    QString money;

signals:
    void crashWindow();

private slots:
    void TimerSlot();

    void on_BackToMain_clicked();

    void on_min_value_button_clicked();

    void on_minus_value_button_clicked();

    void on_x2_value_button_clicked();

    void on_half_value_button_clicked();

    void on_max_value_button_clicked();

    void on_plus_value_button_clicked();

    void on_plus_coeficient_button_clicked();

    void on_minus_coeficient_button_clicked();

    void on_Play_button_clicked();

public slots:
    void slot(QString a, QString b);

private:
    db database;
    Ui::Crash *ui;
    QTimer *timer;
    int time;
};

#endif // CRASH_H
