#ifndef ACCOUNTSETTINGS_H
#define ACCOUNTSETTINGS_H

#include <QDialog>
#include "db.h"
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
};

#endif // ACCOUNTSETTINGS_H
