#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "db.h"

namespace Ui {
class Minesweeper;
}

class Minesweeper : public QWidget
{
    Q_OBJECT

public:
    explicit Minesweeper(QWidget *parent = nullptr);
    ~Minesweeper();
    QString login;
    bool mas[3][5] = { {1, 1, 1, 1, 1},  {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1} };
    int RandomBetween(int,int);
    QString stavka = "0";
    QString money;
    QString bombs = "1";
    QString plus = "1";
    QString coeficient = "1";
    QString max_bombs = "14";
    double MakeCoeficient(int, int);
    bool CheckField(int, int);
    void RecoverButtons();
    void Timer(int);
signals:
    void minesWindow();

private slots:
    void on_BackToMain_clicked();

    void on_b1_3_clicked();

    void on_PlayButton_clicked();

    void on_plus_value_button_clicked();

    void on_minus_value_button_clicked();

    void on_StopButton_clicked();

    void on_b1_1_clicked();

    void on_b1_2_clicked();

    void on_b2_1_clicked();

    void on_b2_2_clicked();

    void on_b2_3_clicked();

    void on_b3_1_clicked();

    void on_b3_2_clicked();

    void on_b3_3_clicked();

    void on_b4_1_clicked();

    void on_b4_2_clicked();

    void on_b4_3_clicked();

    void on_b5_1_clicked();

    void on_b5_2_clicked();

    void on_b5_3_clicked();

    void on_info_clicked();

public slots:
    void slot(QString a);

private:
    Ui::Minesweeper *ui;
    db database;
};

#endif // MINESWEEPER_H
