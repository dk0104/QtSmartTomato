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
const QString PROJECT="project";
const QString EPIC="epic";
const QString TASK="task";
const QString TOMATO="tomato";

class DataBaseConnector
{

public:
    static DataBaseConnector& GetInstance();
    static void CheckQueryResult(const QSqlQuery& guery);
    QHash<QString, DaoBase *> &GetDaoBaseList();
    DataBaseConnector(const DataBaseConnector& ref)=delete;
    DataBaseConnector& operator =(const DataBaseConnector& ref)=delete;
    ~ DataBaseConnector();


protected:
    DataBaseConnector(const QString& path = DB_FILENAME);
private:
    QHash<QString,DaoBase*> mDaoBaseList;
    void InitDaoList();
    void UpdateDAO();
    std::unique_ptr<QSqlDatabase> mDataBase;
};

#endif // DATABASECONNECTOR_H
