#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QString>
#include <memory>
#include "epicdao.h"

class QSqlQuery;
class QSqlDatabase;

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
    const EpicDAO mEpicDao;
private:
    std::unique_ptr<QSqlDatabase> mDataBase;

};

#endif // DATABASECONNECTOR_H