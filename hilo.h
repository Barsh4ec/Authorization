#ifndef HILO_H
#define HILO_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "db.h"

namespace Ui {
class HiLo;
}

class HiLo : public QWidget
{
    Q_OBJECT

public:
    explicit HiLo(QWidget *parent = nullptr);
    ~HiLo();
    QString login;
    QString stavka = "0";
    QString money;
    QString bubna[13] = {":/resources/Cards/2-bubna.png", ":/resources/Cards/3-bubna.png", ":/resources/Cards/4-bubna.png",
                         ":/resources/Cards/5-bubna.png", ":/resources/Cards/6-bubna.png", ":/resources/Cards/7-bubna.png",
                         ":/resources/Cards/8-bubna.png", ":/resources/Cards/9-bubna.png", ":/resources/Cards/10-bubna.png",
                         ":/resources/Cards/11-bubna.png", ":/resources/Cards/12-bubna.png", ":/resources/Cards/13-bubna.png", ":/resources/Cards/14-bubna.png"};
    int ChangeTheCard();
    double MakeLowCoeficient(int);
    double MakeHighCoeficient(int);
signals:
    void HiLoWindow();

private slots:
    void on_BackToMain_clicked();

    void on_minus_button_clicked();

    void on_plus_button_clicked();

    void on__0_1_Button_clicked();

    void on__0_5_Button_clicked();

    void on__1_Button_clicked();

    void on__5_Button_clicked();

    void on__20_Button_clicked();

    void on__100_Button_clicked();

    void on__500_Button_clicked();

    void on_X2_Button_clicked();

    void on_half_button_clicked();

    void on_Change_card_clicked();

    void on_Higher_card_Button_clicked();

    void on_Lower_Card_Button_clicked();

    void on_Take_Cash_clicked();

    void on_play_button_clicked();

public slots:
    void slot(QString a);

private:
    QString cards_in_row = "0";
    QString Total_coeficient = "1";
    bool is_started = false;
    double high_coeficient;
    double low_coeficient;
    int index;
    bool is_plus;
    Ui::HiLo *ui;
    db database;

};

#endif // HILO_H
