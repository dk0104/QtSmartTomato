#include "taskdao.h"
#include "task.h"
#include "project.h"
#include "databaseconnector.h"

#include <QSqlDatabase>;
#include <QString>;
#include <QSqlQuery>;

using namespace std;

TaskDAO::TaskDAO(QSqlDatabase &database):
    mDataBase(database)
{

}

void TaskDAO::Init() const
{
    if(!mDatabase.tables().contains("tasks"))
    {
        QSqlQuery query(mDataBase);
        query.exec(QString("CREATE TABLE tasks")
                   +"(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   +"project_id INTEGER"
                   +"tomato_cnt INTEGER"
                   +"description TEXT)"
                   +"planed_time DATE");
    }
}

void TaskDAO::AddTask(int projectId,Task& task) const
{
    QSqlQuery query(mDataBase);
    query.prepare(QString("INSERT INTO tasks")
            +"(project_id,description,planed_time,tomato_cnt)"
            +"VALUES(:project_id,:description,:planned_time,:tomato_cnt)");
    query.bindValue(":project_id",projectId);
    query.bindValue(":description",task.getDescription());
    query.bindValue(":planned_time",task.getPlanedTime());
    query.bindValue(":planned_time",task.getPlanedTime());
    DataBaseConnector::CheckQueryResult(query);
    task.setId(query.lastInsertId().toInt());
    task.setProjectId(projectId);
}

void TaskDAO::RemoveTask(int id) const
{
    QSqlQuery query(mDataBase);
    query.prepare("DELETE FROM tasks WHERE id = (:id)");
    query.bindValue(":id",id);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);

}

void TaskDAO::UpdateTask(const Task &task) const
{

}

std::unique_ptr<std::vector<std::unique_ptr<Task> > > TaskDAO::GetTasksForProject(int projectId) const
{
    QSqlQuery query(mDataBase);

    query.prepare("SELECT * FROM tasks WHERE projet_id = (:project_id)");
    query.bindValue(":project_id", projectId);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
    unique_ptr<vector<unique_ptr<Task>>> list(new vector<unique_ptr<Task>>());
    while(query.next()) {
        unique_ptr<Task> task(new Task());
        task->setId(query.value("id").toInt());
        task->setProjectId(query.value("project_id").toInt());
        task->setDescription(query.value("description").toString());
        task->setPlanedTime(query.value("planned_time").toString());
        list->push_back(move(task));
    }
    return list;

}
