#include "epicdao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include "databaseconnector.h"

EpicDAO::EpicDAO(QSqlDatabase &database):
    mDatabase(database)
{

}

void EpicDAO::init() const
{
    if(!mDatabase.tables().contains("epic")){
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE epic (id INTEGER KEY AUTOINKREMENT, name TEXT)");
        DataBaseConnector::CheckQueryResult(query);
    }

}
