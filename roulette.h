#ifndef ROULETTE_H
#define ROULETTE_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "db.h"

namespace Ui {
class Roulette;
}

class Roulette : public QWidget
{
    Q_OBJECT

public:
    explicit Roulette(QWidget *parent = nullptr);
    ~Roulette();
    QString login;
    QString password;
    QString stavka = "1";
    QString plus = "1";
    QString money;
    QString mas[15] = {"green", "red", "black", "red", "black", "red", "black", "red", "black", "red", "black", "red", "black", "red", "black"};
    QString history[8] = {"#8E8EC7", "#8E8EC7", "#8E8EC7", "#8E8EC7", "#8E8EC7", "#8E8EC7", "#8E8EC7", "#8E8EC7"};

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

public slots:
    void slot(QString a, QString b);

private:
    void ChangeHistory(QString);
    db database;
    Ui::Roulette *ui;
    Roulette *roulette;
};

#endif // ROULETTE_H
