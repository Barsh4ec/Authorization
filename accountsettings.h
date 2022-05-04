#ifndef ACCOUNTSETTINGS_H
#define ACCOUNTSETTINGS_H

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

private:
    Ui::AccountSettings *ui;
};

#endif // ACCOUNTSETTINGS_H
