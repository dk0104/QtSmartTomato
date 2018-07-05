#include "taskdao.h"
#include "task.h"
#include "project.h"
#include "databaseconnector.h"

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QVariant>

using namespace std;

TaskDAO::TaskDAO(QSqlDatabase &database):
    m_SataBase(database)
{

}

void TaskDAO::Init() const
{
    if(!m_SataBase.tables().contains("tasks"))
    {
        QSqlQuery query(m_SataBase);
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
    QSqlQuery query(m_SataBase);
    query.prepare(QString("INSERT INTO tasks")
            +"(project_id,description,planed_time,tomato_cnt)"
            +"VALUES(:project_id,:description,:planned_time,:tomato_cnt)");
    query.bindValue(":project_id",task.getProjectId());
    query.bindValue(":description",task.getDescription());
    query.bindValue(":planned_time",task.getPlanedTime());
    query.bindValue(":planned_time",task.getPlanedTime());
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
    task.setId(query.lastInsertId().toInt());
    task.setProjectId(projectId);
}

void TaskDAO::RemoveTask(int id) const
{
    QSqlQuery query(m_SataBase);
    query.prepare("DELETE FROM tasks WHERE id = (:id)");
    query.bindValue(":id",id);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);

}

void TaskDAO::UpdateTask(const Task &task) const
{
    QSqlQuery query(m_SataBase);
    query.prepare(QString("UPDATE tasks ")
                  +"SET "
                  +"name=(:name)" 
                  +"project_id=(:project_id) "
                  +"tomato_cnt=(:tomato_cnt)"
                  +"description=(:description)"
                  +"planned_time=(:planned_time)"+
                  "WHERE id=(:id)");
    query.bindValue(":name",task.getName());
    query.bindValue(":project_id",task.getProjectId());
    query.bindValue(":tomato_cnt",task.getTomatoCounter());
    query.bindValue(":description",task.getDescription());
    query.bindValue(":planned_time",task.getPlanedTime());
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
}

std::unique_ptr<std::vector<std::unique_ptr<Task> > > TaskDAO::GetTasksForProject(int projectId) const
{
    QSqlQuery query(m_SataBase);

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
        task->setPlanedTime(query.value("planned_time").toDate());
        list->push_back(move(task));
    }
    return list;
}
