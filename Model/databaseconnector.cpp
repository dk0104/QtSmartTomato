#include "databaseconnector.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DataBaseConnector::DataBaseConnector(const QString& path):
    mDataBase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    mEpicDao(*mDataBase)
{
    mDataBase->setDatabaseName(path);
    auto openResult = mDataBase->open();
    qDebug() << "Database connection: " << (openResult?"OK":"KO")<<endl;
    mEpicDao.init();
}

DataBaseConnector &DataBaseConnector::GetInstance()
{
   static DataBaseConnector dbc;
   return dbc;
}

void DataBaseConnector::CheckQueryResult(const QSqlQuery &query)
{
    if(query.lastError().type() == QSqlError::ErrorType::NoError){
        qDebug() << "Querry OK " << query.lastQuery();
    } else {
        qWarning() << "Query KO:" << query.lastError().text();
        qWarning() << "Query text:" << query.lastQuery();
    }
}
