#ifndef PROJECTDAO_H
#define PROJECTDAO_H

#include <memory>
#include <vector>

// Forward decl
class QSqlDatabase;
class QString;
class Project;


class ProjectDAO
{
public:
    ProjectDAO(QSqlDatabase& database);
    void Init() const;
    void AddProject(Project& project);
    void UpdateProject(const Project& project) const;
    void RemoveProject(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Project>>> GetProjects() const;
private:
    QSqlDatabase& mSqlDatabase;
};

#endif // PROJECTDAO_H
