#ifndef ROULETTE_H
#define ROULETTE_H

#include <QWidget>

namespace Ui {
class Roulette;
}

class Roulette : public QWidget
{
    Q_OBJECT

public:
    explicit Roulette(QWidget *parent = nullptr);
    ~Roulette();
    QString login;

signals:
    void fWindow();

private slots:
    void on_BakToMain1_clicked();

public slots:
    void slot(QString a);

private:
    Ui::Roulette *ui;
};

#endif // ROULETTE_H
