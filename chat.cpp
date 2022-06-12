#include "chat.h"
#include "ui_chat.h"
#include <QDebug>

Chat::Chat(QWidget *parent, QString login) :
    QDialog(parent),
    ui(new Ui::Chat)
{
    this->login = login;
      ui->setupUi(this);
      socket = new QTcpSocket(this);
      connect(socket, &QTcpSocket::readyRead, this, &Chat::slotReadyRead);
      connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
      nextBlockSize = 0;
      this->setWindowTitle(QObject::tr("Чат"));
  }

  Chat::~Chat()
  {
      delete ui;
  }

  void Chat::on_connect_Button_clicked()
  {
      socket->connectToHost("127.0.0.1", 2323);
  }

  void Chat::SendToServer(QString str)
  {
      Data.clear();
      QDataStream out(&Data, QIODevice::WriteOnly);
      out.setVersion(QDataStream::Qt_6_3);
      qDebug() << login << "123";
      out << quint16(0) << login << str;
      out.device()->seek(0);
      out << quint16(Data.size() - sizeof(quint16));
      socket->write(Data);
      ui->lineEdit->setText("");
  }

  void Chat::slotReadyRead()
  {
      QDataStream in(socket);
      in.setVersion(QDataStream::Qt_6_3);
      if(in.status() == QDataStream::Ok)
      {
          for(;;)
          {
              if(nextBlockSize == 0)
              {
                  if(socket->bytesAvailable() < 2)
                  {
                      break;
                  }
                  in >> nextBlockSize;
              }
              if(socket->bytesAvailable() < nextBlockSize)
              {
                  break;
              }

              QString str;
              QString login;
              in >> login >> str;
              nextBlockSize = 0;
              ui->textBrowser->append(login + ": " + str);
          }
      } else {
          ui->textBrowser->append("read error");
      }
  }
  void Chat::on_Send_Message_clicked()
  {
      SendToServer(ui->lineEdit->text());
  }

  void Chat::on_lineEdit_returnPressed()
  {
      SendToServer(ui->lineEdit->text());
  }
