#include "projectdao.h"
#include "databaseconnector.h"
#include "project.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace std;
ProjectDAO::ProjectDAO(QSqlDatabase &database):
    DaoBase(database)
{
}

ProjectDAO::~ProjectDAO()
{

}

void ProjectDAO::Init() const
{
    if (!mDataBaseRef.tables().contains("projects")) {
        QSqlQuery query(mDataBaseRef);
        query.exec("CREATE TABLE projects (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        DataBaseConnector::CheckQueryResult(query);
    }
}

void ProjectDAO::AddProject(Project &project)
{
    QSqlQuery query(mDataBaseRef);
    query.prepare("INSERT INTO projekts (name) VALUES (:name),");
    query.bindValue(":name",project.getName());
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
    project.setId(query.lastInsertId().toInt());
}

void ProjectDAO::UpdateProject(const Project &project) const
{
    QSqlQuery query(mDataBaseRef);
    query.prepare("UPDATE projects SET name=(:name) WHERE id = (:id)");
    query.bindValue(":name",project.getName());
    query.bindValue(":id",project.getId());
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
}

void ProjectDAO::RemoveProject(int id)
{
    QSqlQuery query(mDataBaseRef);
    query.prepare("DELETE FROM projects WHERE id = (:id)");
    query.bindValue(":id",id);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
}

unique_ptr<vector<unique_ptr<Project> > > ProjectDAO::GetProjects() const
{
    QSqlQuery query("SELECT * FROM projects",mDataBaseRef);
    query.exec();
    DataBaseConnector::CheckQueryResult(query);
    unique_ptr<vector<unique_ptr<Project>>> list(new vector<unique_ptr<Project>>());
    while (query.next()) {
        unique_ptr<Project> project(new Project());
        project->setId(query.value("id").toInt());
        project->setName(query.value("name").toString());
        list->push_back(move(project));
    }
    return list;
}
