#include "databaseconnector.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "daobase.h"
#include "epicdao.h"
#include "projectdao.h"
#include "taskdao.h"
#include "tomatodao.h"

DataBaseConnector::DataBaseConnector(const QString& path):
    mDataBase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
{
    InitDaoList();
    mDataBase->setDatabaseName(path);
    auto openResult = mDataBase->open();
    qDebug() << "Database connection: " << (openResult?"OK":"KO")<<endl;
    UpdateDAO();
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

DataBaseConnector::~DataBaseConnector()
{

}

void DataBaseConnector::InitDaoList(){
    mDaoBaseList=std::make_unique<QHash<QString,const DaoBase*>>();
    (*mDaoBaseList)[EPIC] = new EpicDAO(*mDataBase);
    (*mDaoBaseList)[PROJECT] = new ProjectDAO(*mDataBase);
    (*mDaoBaseList)[TASK] = new TaskDAO(*mDataBase);
    (*mDaoBaseList)[TOMATO] = new TomatoDAO(*mDataBase);
}

void DataBaseConnector::UpdateDAO()
{
    for(auto& key : mDaoBaseList->keys()){
        (*mDaoBaseList)[key]->Init();
    }
}
