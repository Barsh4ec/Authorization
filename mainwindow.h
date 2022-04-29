#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <roulette.h>
#include <slots.h>
#include <blackjack.h>
#include <hilo.h>
#include <crash.h>
#include <minesweeper.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RouletteButton_clicked();

    void on_slotsButton_clicked();

    void on_BJButton_clicked();

    void on_HiLoButton_clicked();

    void on_CrashButton_clicked();

    void on_MinesButton_clicked();

private:
    Ui::MainWindow *ui;
    Roulette *roulette;
    Slots *slotte;
    BlackJack *blackjack;
    HiLo *hilo;
    Crash *crash;
    Minesweeper *minesweeper;
};

#endif // MAINWINDOW_H
