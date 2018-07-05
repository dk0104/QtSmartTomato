#include "tomatodao.h"
#include "databaseconnector.h"
#include "task.h"
#include "tomato.h"

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QVariant>

using namespace std;

TomatoDAO::TomatoDAO(QSqlDatabase &database):
    dataBase(database)
{
}

void TomatoDAO::Init() const
{
    if(!dataBase.tables().contains("tomatos")){
        QSqlQuery query(dataBase);
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
    QSqlQuery query(dataBase);
    query.prepare(QString("INSERT INTO tomatos")
                  +"(task_id,state,started_time,completed_time)"
                  +"VALUES(:task_id,:state,:started_time,:completed_time)");
    query.bindValue(":task_id",tomato.getTaskId());
    query.bindValue(":state",tomato.processState());
    query.bindValue(":started_time",tomato.startTime());
    query.bindValue(":completed_time",tomato.completedTime());
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
}

void TomatoDAO::RemoveTomato(int id) const
{
    QSqlQuery query(dataBase);
    query.prepare("DELETE FROM tomatos WHERE id = (:id)");
    query.bindValue(":id",id);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
}

void TomatoDAO::UpdateTomato(const Tomato& tomato) const
{
    QSqlQuery query(dataBase);
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

unique_ptr<vector<unique_ptr<Tomato> > > TomatoDAO::GetTomatoForTask(int taskId) const
{
    QSqlQuery query(dataBase);
    query.prepare("SELECT * FROM tomatos WHERE task_id = (:task_id)");
    query.bindValue(":task_id",taskId);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
    unique_ptr<vector<unique_ptr<Tomato>>> list(new vector<unique_ptr<Tomato>>());
    while(query.next()) {
        unique_ptr<Tomato> tomato(new Tomato());
        tomato->setID(query.value("id").toInt());
        list->push_back(move(tomato));
    }
    return list;
}
