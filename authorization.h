#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QMainWindow>
#include "registrationwindow.h"
#include <mainwindow.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class Authorization; }
QT_END_NAMESPACE

class Authorization : public QMainWindow
{
    Q_OBJECT

public:
    Authorization(QWidget *parent = nullptr);
    ~Authorization();

    void SetLogin(QString value) { login = value; }
    void SetPassword(QString value) { password = value; }

    QString GetLogin() { return login; }
    QString GetPassword() { return password; }

private slots:
    void on_RegistrationButton_clicked();

    void on_EnterButton_clicked();

    void on_CheckPass_stateChanged(int arg1);

private:
    QString login;
    QString password;
    Ui::Authorization *ui;
    RegistrationWindow *sWindow;
    MainWindow *mWindow;
    QSqlDatabase database;

};
#endif // AUTHORIZATION_H
