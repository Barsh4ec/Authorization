#ifndef ADDMONEY_H
#define ADDMONEY_H

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

signals:
    void addMWindow();

private slots:
    void on_back_to_main_clicked();

public slots:
    void slot(QString a);

private:
    Ui::AddMoney *ui;
};

#endif // ADDMONEY_H
