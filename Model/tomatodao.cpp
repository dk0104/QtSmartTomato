#include "tomatodao.h"
#include "databaseconnector.h"
#include "task.h"
#include "tomato.h"

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
    DataBaseConnector::CheckQueryResult(query);
    }
}

void TomatoDAO::AddTomato(Tomato &tomato)
{
    QSqlQuery query(mDataBase);
    query.prepare(QSting("INSERT INTO tomatos")
                  +"(task_id,state,started_time,completed_time)"
                  +"VALUES(:task_id,:state,:started_time,:completed_time)");
    query.bindValue(":task_id",tomato.getTaskId());
    query.bindValue(":state",tomato.processState());
    query.bindValue(":started_time",tomato.startTime());
    query.bindValue(":completed_time",tomato.completedTime());
    query.exec();
    DataBaseConnector::CheckQuerryResult(query);
}

void TomatoDAO::RemoveTomato(int id) const
{
    QSqlQuery query(mDataBase);
    query.prepare("DELETE FROM tomatos WHERE id = (:id)");
    query.bildValue(":id",id);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
}

void TomatoDAO::UpdateTomato(const Tomato& tomato) const
{
    QSqlQuery query(mDataBase);
    query.prepare(QString("UPDATE tomatos SET")
            +"processState =(:processState)"
            +"taskId=(:taskId)"
            +"started_time=(:started_time)"
            +"completed_time=(:completed_time)"
            +"WHERE id = (:id)");
    query.bindValue(":processState",tomato.processState());
    query.bindValue(":id", tomato.Id());
    query.bindValue(":task_id",tomato.getTaskId());
    query.bindValue(":started_time",tomato.startTime());
    query.bindValue(":completed_time",tomato.completedTime());
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
}

std::unique_ptr<std::vector<std::unique_ptr<Tomato> > > TomatoDAO::GetTomatoForTask(int taskId) const
{
    QSqlQuery query(mDataBase);
    query.prepare("SELECT * FROM tomatos WHERE task_id = (:task_id)");
    query.bindValue("task_id".task_id);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
    unique_ptr<vector<unique_ptr<Tomato>>> list(new vector<unique_ptr<Tomato>>());
    while(query.next()) {
        unique_ptr<Tomato> tomato(new Tomato());
        tomato->setId(query.value("id").toInt());

        list->push_back(move(tomato));
    }
    return list;

}
