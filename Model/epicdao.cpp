#include "epicdao.h"
#include "databaseconnector.h"
#include "epic.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace std;

EpicDAO::EpicDAO(QSqlDatabase &db):
    DaoBase(db)
{
}

EpicDAO::~EpicDAO()
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

unique_ptr<Epic> EpicDAO::GetEpic(int id)
{
   QSqlQuery q(mDataBaseRef);
   q.prepare("SELECT * FROM epic WHERE id = (:id)");
   q.bindValue(":id",id);
   q.exec();
   DataBaseConnector::CheckQueryResult(q);
   unique_ptr<Epic> epic(new Epic());
   epic->setId(q.value("id").toInt());
   epic->setName(q.value("name").toString());
   return epic;
}
