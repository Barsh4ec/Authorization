#ifndef ADDMONEY_H
#define ADDMONEY_H
#include "db.h"
#include <QDialog>

namespace Ui {
class AddMoney;
}

class AddMoney : public QDialog
{
    Q_OBJECT

public:
    explicit AddMoney(QWidget *parent = nullptr);
    ~AddMoney();
    QString login;
    void balance_func(QString amount, QString promo, QString bill);
    QString promos[5] = {"10","20","30","40","50"};
signals:
    void addMWindow();

private slots:
    void on_back_to_main_clicked();

    void on_pushButton_clicked();

public slots:
    void slot(QString a);

private:
    Ui::AddMoney *ui;
    db database;
    QString amount;

};

#endif // ADDMONEY_H
