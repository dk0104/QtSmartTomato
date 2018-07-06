#include "epicdao.h"
#include "databaseconnector.h"

#include <QSqlDatabase>
#include <QSqlQuery>


EpicDAO::EpicDAO(QSqlDatabase &db):
    DaoBase(db)
{
}

void EpicDAO::Init() const
{
    if(!mDataBaseRef.tables().contains("epic")){
        QSqlQuery query(mDataBaseRef);
        query.exec("CREATE TABLE epic (id INTEGER KEY AUTOINKREMENT, name TEXT)");
        DataBaseConnector::CheckQueryResult(query);
    }
}
