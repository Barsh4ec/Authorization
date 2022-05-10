#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QWidget>

namespace Ui {
class BlackJack;
}

class BlackJack : public QWidget
{
    Q_OBJECT

public:
    explicit BlackJack(QWidget *parent = nullptr);
    ~BlackJack();
    QString login;

signals:
    void bjWindow();

private slots:
    void on_BackToMain_clicked();

public slots:
    void slot(QString a);

private:
    Ui::BlackJack *ui;
};

#endif // BLACKJACK_H
