#include "database.h"
#include <iostream>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>

DataBase::DataBase(QWidget *parent)
    : QMainWindow{parent}
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName ("caligulas.c5gym54nkb1s.us-east-1.rds.amazonaws.com");
    db.setUserName("admin");
    db.setPassword("adminadmin");
    db.setDatabaseName ("caligula_users");
    if(db.open()) {
        std::cout << "Database Connected Successfully";
    } else {
        std::cout << "Database Connected Failed";
    }

}
