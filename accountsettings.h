#ifndef ACCOUNTSETTINGS_H
#define ACCOUNTSETTINGS_H
#include "db.h"
#include <QDialog>
namespace Ui {
class AccountSettings;
}

class AccountSettings : public QDialog
{
    Q_OBJECT

public:
    explicit AccountSettings(QWidget *parent = nullptr);
    ~AccountSettings();

signals:
    void AccountSettWindow();

private slots:
    void on_BackToMain_clicked();

    void on_button_change_name_clicked();

private:
    Ui::AccountSettings *ui;
    db database;
    QString login;
};

#endif // ACCOUNTSETTINGS_H
