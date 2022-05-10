#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <roulette.h>
#include <slots.h>
#include <blackjack.h>
#include <hilo.h>
#include <crash.h>
#include <minesweeper.h>
#include <addmoney.h>
#include <accountsettings.h>
#include <settings.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, QString = "0", QString = "0");
    ~MainWindow();
    QString login;

private slots:
    void on_RouletteButton_clicked();

    void on_slotsButton_clicked();

    void on_BJButton_clicked();

    void on_HiLoButton_clicked();

    void on_CrashButton_clicked();

    void on_MinesButton_clicked();

    void on_PopovnytyRachunok_clicked();

    void on_AccountSettings_clicked();

    void on_SettingsButon_clicked();

signals:
    void roulettesignal(QString);
    void slotssignal(QString);
    void bjsignal(QString);
    void hilosignal(QString);
    void crashsignal(QString);
    void minessignal(QString);
    void addmsignal(QString);
    void accsignal(QString);
    void settsignal(QString);

private:
    Ui::MainWindow *ui;
    Roulette *roulette;
    Slots *slotte;
    BlackJack *blackjack;
    HiLo *hilo;
    Crash *crash;
    Minesweeper *minesweeper;
    AddMoney *addmoney;
    AccountSettings *accsett;
    Settings *settings;
};

#endif // MAINWINDOW_H
