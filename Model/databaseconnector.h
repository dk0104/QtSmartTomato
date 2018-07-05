#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QString>
#include <QHash>
#include <memory>
#include <vector>

class QSqlQuery;
class QSqlDatabase;
class DaoBase;

const QString DB_FILENAME = "tomato.db";

class DataBaseConnector
{

public:
    static DataBaseConnector& GetInstance();
    static void CheckQueryResult(const QSqlQuery& guery);
    DataBaseConnector(const DataBaseConnector& ref)=delete;
    DataBaseConnector& operator =(const DataBaseConnector& ref)=delete;
    ~ DataBaseConnector();


protected:
    DataBaseConnector(const QString& path = DB_FILENAME);
public:
     std::unique_ptr<QHash<QString,const DaoBase*>> mDaoBaseList;
private:
    void InitDaoList();
    std::unique_ptr<QSqlDatabase> mDataBase;
};

#endif // DATABASECONNECTOR_H
