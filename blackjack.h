#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "db.h"

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
    int ChangeDealerCard();
    int ChangePlayerCard();
    int player_card;
    int dealer_card;
    int Make_score(int);
    int player_step = 0;
    int dealer_step = 0;
    void Stop_Game();
    void Timer(int);
    void AddMoney();
    void TakeMoney();

signals:
    void bjWindow();

private slots:
    void on_BackToMain_clicked();

    void on_StartGame_clicked();

    void on_Stay_clicked();

    void on_Add_clicked();

    void on_info_clicked();

public slots:
    void slot(QString a);

private:
    QString bubna[13] = {":/resources/Smaller_Cards/2-bubna.png", ":/resources/Smaller_Cards/3-bubna.png", ":/resources/Smaller_Cards/4-bubna.png",
                         ":/resources/Smaller_Cards/5-bubna.png", ":/resources/Smaller_Cards/6-bubna.png", ":/resources/Smaller_Cards/7-bubna.png",
                         ":/resources/Smaller_Cards/8-bubna.png", ":/resources/Smaller_Cards/9-bubna.png", ":/resources/Smaller_Cards/10-bubna.png",
                         ":/resources/Smaller_Cards/11-bubna.png", ":/resources/Smaller_Cards/12-bubna.png", ":/resources/Smaller_Cards/13-bubna.png", ":/resources/Smaller_Cards/14-bubna.png"};
    QString cherva[13] = {":/resources/Smaller_Cards/2-cherva.png", ":/resources/Smaller_Cards/3-cherva.png", ":/resources/Smaller_Cards/4-cherva.png",
                         ":/resources/Smaller_Cards/5-cherva.png", ":/resources/Smaller_Cards/6-cherva.png", ":/resources/Smaller_Cards/7-cherva.png",
                         ":/resources/Smaller_Cards/8-cherva.png", ":/resources/Smaller_Cards/9-cherva.png", ":/resources/Smaller_Cards/10-cherva.png",
                         ":/resources/Smaller_Cards/11-cherva.png", ":/resources/Smaller_Cards/12-cherva.png", ":/resources/Smaller_Cards/13-cherva.png", ":/resources/Smaller_Cards/14-cherva.png"};
    QString pika[13] = {":/resources/Smaller_Cards/2-pika.png", ":/resources/Smaller_Cards/3-pika.png", ":/resources/Smaller_Cards/4-pika.png",
                         ":/resources/Smaller_Cards/5-pika.png", ":/resources/Smaller_Cards/6-pika.png", ":/resources/Smaller_Cards/7-pika.png",
                         ":/resources/Smaller_Cards/8-pika.png", ":/resources/Smaller_Cards/9-pika.png", ":/resources/Smaller_Cards/10-pika.png",
                         ":/resources/Smaller_Cards/11-pika.png", ":/resources/Smaller_Cards/12-pika.png", ":/resources/Smaller_Cards/13-pika.png", ":/resources/Smaller_Cards/14-pika.png"};
    QString hresta[13] = {":/resources/Smaller_Cards/2-hresta.png", ":/resources/Smaller_Cards/3-hresta.png", ":/resources/Smaller_Cards/4-hresta.png",
                         ":/resources/Smaller_Cards/5-hresta.png", ":/resources/Smaller_Cards/6-hresta.png", ":/resources/Smaller_Cards/7-hresta.png",
                         ":/resources/Smaller_Cards/8-hresta.png", ":/resources/Smaller_Cards/9-hresta.png", ":/resources/Smaller_Cards/10-hresta.png",
                         ":/resources/Smaller_Cards/11-hresta.png", ":/resources/Smaller_Cards/12-hresta.png", ":/resources/Smaller_Cards/13-hresta.png", ":/resources/Smaller_Cards/14-hresta.png"};

    QString dealer_bubna[13] = {":/resources/Much_Smaller_Cards/2-bubna.png", ":/resources/Much_Smaller_Cards/3-bubna.png", ":/resources/Much_Smaller_Cards/4-bubna.png",
                         ":/resources/Much_Smaller_Cards/5-bubna.png", ":/resources/Much_Smaller_Cards/6-bubna.png", ":/resources/Much_Smaller_Cards/7-bubna.png",
                         ":/resources/Much_Smaller_Cards/8-bubna.png", ":/resources/Much_Smaller_Cards/9-bubna.png", ":/resources/Much_Smaller_Cards/10-bubna.png",
                         ":/resources/Much_Smaller_Cards/11-bubna.png", ":/resources/Much_Smaller_Cards/12-bubna.png", ":/resources/Much_Smaller_Cards/13-bubna.png", ":/resources/Much_Smaller_Cards/14-bubna.png"};
    QString dealer_cherva[13] = {":/resources/Much_Smaller_Cards/2-cherva.png", ":/resources/Much_Smaller_Cards/3-cherva.png", ":/resources/Much_Smaller_Cards/4-cherva.png",
                         ":/resources/Much_Smaller_Cards/5-cherva.png", ":/resources/Much_Smaller_Cards/6-cherva.png", ":/resources/Much_Smaller_Cards/7-cherva.png",
                         ":/resources/Much_Smaller_Cards/8-cherva.png", ":/resources/Much_Smaller_Cards/9-cherva.png", ":/resources/Much_Smaller_Cards/10-cherva.png",
                         ":/resources/Much_Smaller_Cards/11-cherva.png", ":/resources/Much_Smaller_Cards/12-cherva.png", ":/resources/Much_Smaller_Cards/13-cherva.png", ":/resources/Much_Smaller_Cards/14-cherva.png"};
    QString dealer_pika[13] = {":/resources/Much_Smaller_Cards/2-pika.png", ":/resources/Much_Smaller_Cards/3-pika.png", ":/resources/Much_Smaller_Cards/4-pika.png",
                         ":/resources/Much_Smaller_Cards/5-pika.png", ":/resources/Much_Smaller_Cards/6-pika.png", ":/resources/Much_Smaller_Cards/7-pika.png",
                         ":/resources/Much_Smaller_Cards/8-pika.png", ":/resources/Much_Smaller_Cards/9-pika.png", ":/resources/Much_Smaller_Cards/10-pika.png",
                         ":/resources/Much_Smaller_Cards/11-pika.png", ":/resources/Much_Smaller_Cards/12-pika.png", ":/resources/Much_Smaller_Cards/13-pika.png", ":/resources/Much_Smaller_Cards/14-pika.png"};
    QString dealer_hresta[13] = {":/resources/Much_Smaller_Cards/2-hresta.png", ":/resources/Much_Smaller_Cards/3-hresta.png", ":/resources/Much_Smaller_Cards/4-hresta.png",
                         ":/resources/Much_Smaller_Cards/5-hresta.png", ":/resources/Much_Smaller_Cards/6-hresta.png", ":/resources/Much_Smaller_Cards/7-hresta.png",
                         ":/resources/Much_Smaller_Cards/8-hresta.png", ":/resources/Much_Smaller_Cards/9-hresta.png", ":/resources/Much_Smaller_Cards/10-hresta.png",
                         ":/resources/Much_Smaller_Cards/11-hresta.png", ":/resources/Much_Smaller_Cards/12-hresta.png", ":/resources/Much_Smaller_Cards/13-hresta.png", ":/resources/Much_Smaller_Cards/14-hresta.png"};
    Ui::BlackJack *ui;
    QString stavka;
    QString money;
    QString player_score = "0";
    QString dealer_score = "0";
    db database;
    bool is_started = false;
    bool Dealer_stop = false;
};

#endif // BLACKJACK_H
