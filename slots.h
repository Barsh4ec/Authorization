#ifndef SLOTS_H
#define SLOTS_H

#include <QWidget>

namespace Ui {
class Slots;
}

class Slots : public QWidget
{
    Q_OBJECT

public:
    explicit Slots(QWidget *parent = nullptr);
    ~Slots();

signals:
    void slotsWindow();

private slots:
    void on_BackToMain_clicked();

private:
    Ui::Slots *ui;
};

#endif // SLOTS_H
