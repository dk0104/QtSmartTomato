#include "epicdao.h"
#include "databaseconnector.h"

#include <QSqlDatabase>


EpicDAO::EpicDAO(QSqlDatabase& db):
    m_DataBase(db)
{
}

void EpicDAO::Init() const
{
    if(!m_DataBase.tables().contains("epic")){
        QSqlQuery query(m_DataBase);
        query.exec("CREATE TABLE epic (id INTEGER KEY AUTOINKREMENT, name TEXT)");
        DataBaseConnector::CheckQueryResult(query);
    }
}
