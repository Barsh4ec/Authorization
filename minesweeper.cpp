#include "minesweeper.h"
#include "ui_minesweeper.h"

Minesweeper::Minesweeper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Minesweeper)
{
    ui->setupUi(this);
    setWindowTitle("Minesweeper");
    this->resize(1040, 700);
}

Minesweeper::~Minesweeper()
{
    delete ui;
}

void Minesweeper::on_BackToMain_clicked()
{
    this->close();
    emit minesWindow();
}

