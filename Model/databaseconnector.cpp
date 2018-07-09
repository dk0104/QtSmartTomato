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
    for(auto& key : mDaoBaseList->keys()){
        (*mDaoBaseList)[key]->Init();
    }
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
    (*mDaoBaseList)["Epic"] = new EpicDAO(*mDataBase);
    (*mDaoBaseList)["Project"] = new ProjectDAO(*mDataBase);
    (*mDaoBaseList)["Task"] = new TaskDAO(*mDataBase);
    (*mDaoBaseList)["Tomato"] = new TomatoDAO(*mDataBase);
}
