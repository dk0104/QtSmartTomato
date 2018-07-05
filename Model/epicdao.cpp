#include "epicdao.h"
#include "databaseconnector.h"

#include <QSqlDatabase>
#include <QSqlQuery>


EpicDAO::EpicDAO(QSqlDatabase &db):
    DaoBase(db),
    m_Database(db)
{

}

void EpicDAO::Init() const
{
    if(!m_Database.tables().contains("epic")){
        QSqlQuery query(m_Database);
        query.exec("CREATE TABLE epic (id INTEGER KEY AUTOINKREMENT, name TEXT)");
        DataBaseConnector::CheckQueryResult(query);
    }
}
