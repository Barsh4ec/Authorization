#include "db.h"
#include <iostream>

void db::db_connect(){

    database = QSqlDatabase::addDatabase("QMYSQL", "db_con");
    database.setHostName("caligulas.c5gym54nkb1s.us-east-1.rds.amazonaws.com");
    database.setDatabaseName("caligula_users");
    database.setUserName("admin");
    database.setPassword("adminadmin");
    database.setPort(3306);


    if(database.open())
        {
      qDebug()<<"Successful connection";
        }
    else
    {
      qDebug()<<"The error occured";
    }

}

QSqlQuery db::query_func(QString s){
    QSqlQuery query(QSqlDatabase::database("db_con"));
    query.prepare(QString(s));
    if(!query.exec()){
        qDebug() << "query failed";
    }
    return query;
}




db::db()
{

}
