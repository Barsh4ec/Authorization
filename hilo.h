#ifndef HILO_H
#define HILO_H

#include <QWidget>

namespace Ui {
class HiLo;
}

class HiLo : public QWidget
{
    Q_OBJECT

public:
    explicit HiLo(QWidget *parent = nullptr);
    ~HiLo();

signals:
    void HiLoWindow();

private slots:
    void on_BackToMain_clicked();

private:
    Ui::HiLo *ui;
};

#endif // HILO_H
