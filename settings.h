#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    QString login;

    void Write(QString, QByteArray);
    QByteArray Read(QString);

signals:
    void SettingsWindow();

private slots:
    void on_BackToMain_clicked();

    void on_lang_button_clicked();

    void on_theme_button_clicked();

public slots:
    void slot(QString a);

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
