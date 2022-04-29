#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

signals:
    void firstWindow();

private slots:

    void on_Back_To_Authorization_clicked();

    void on_FinishRagistration_clicked();

    void on_RegPassCheck_stateChanged(int arg1);

private:
    Ui::RegistrationWindow *ui;
    QSqlDatabase db;

};

#endif // REGISTRATIONWINDOW_H
