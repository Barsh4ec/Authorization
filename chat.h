#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

    public:
        explicit Chat(QWidget *parent = nullptr, QString login = "");
        ~Chat();

    private slots:
        void on_connect_Button_clicked();

        void on_Send_Message_clicked();

        void on_lineEdit_returnPressed();

    private:
        QString login;
        Ui::Chat *ui;
        QTcpSocket *socket;
        QByteArray Data;
        void SendToServer(QString str);
        quint16 nextBlockSize;

    public slots:
        void slotReadyRead();
};

#endif // CHAT_H
