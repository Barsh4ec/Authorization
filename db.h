#ifndef DB_H
#define DB_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QException>
class db
{
public:
    db();
    void db_connect();
private:
    QSqlDatabase database;


};

#endif // DB_H
