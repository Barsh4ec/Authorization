#ifndef CRASH_H
#define CRASH_H

#include <QWidget>

namespace Ui {
class Crash;
}

class Crash : public QWidget
{
    Q_OBJECT

public:
    explicit Crash(QWidget *parent = nullptr);
    ~Crash();
    QString login;

signals:
    void crashWindow();

private slots:
    void on_BackToMain_clicked();

public slots:
    void slot(QString a);

private:
    Ui::Crash *ui;
};

#endif // CRASH_H
