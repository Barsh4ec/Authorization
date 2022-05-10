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
    QString login;

signals:
    void AccountSettWindow();

private slots:
    void on_BackToMain_clicked();

    void on_button_change_name_clicked();

public slots:
    void slot(QString a);

private:
    Ui::AccountSettings *ui;
    db database;
};

#endif // ACCOUNTSETTINGS_H
