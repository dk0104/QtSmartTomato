#ifndef PROJECTDAO_H
#define PROJECTDAO_H

#include "daobase.h"
#include <memory>
#include <vector>

// Forward decl
class QString;
class Project;


class ProjectDAO : public DaoBase
{
public:
    ProjectDAO(QSqlDatabase& database);
    void Init() const override;
    void AddProject(Project& project);
    void UpdateProject(const Project& project) const;
    void RemoveProject(int id);
    std::unique_ptr<std::vector<std::unique_ptr<Project>>> GetProjects() const;
};

#endif // PROJECTDAO_H
