#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QWidget>

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

signals:
    void minesWindow();

private slots:
    void on_BackToMain_clicked();

public slots:
    void slot(QString a);

private:
    Ui::Minesweeper *ui;
};

#endif // MINESWEEPER_H
