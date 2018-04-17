#include "tomatodao.h"
#include "task.h"

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QVariant>

TomatoDAO::TomatoDAO(QSqlDatabase &database):
    mDataBase(database)
{
}

void TomatoDAO::Init() const
{
    if(!mDataBase.tables().contains("tomatos")){
        QSqlQuery query(mDataBase);
        query.exec(QString("CREATE TABLE tomatos")
                   +"(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   +"task_id INTEGER"
                   +"state INTEGER"
                   +"started_time TIME"
                   +"completed_time TIME");
    }

}

void TomatoDAO::AddTomato(int taskId, Tomato &tomato)
{

}

void TomatoDAO::RemoveTomato(int id) const
{

}

std::unique_ptr<std::vector<std::unique_ptr<Tomato> > > TomatoDAO::GetTomatoForTask(int taskId) const
{

}
