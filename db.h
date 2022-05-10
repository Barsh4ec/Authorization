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
    QSqlQuery query_func(QString s);
    void get_data(QString login, QString password);
    QString extract_log();
    QString extract_pas();
public slots:
    void slot(QString a);
private:
    QSqlDatabase database;
    QString login;
    QString password;

};

#endif // DB_H
