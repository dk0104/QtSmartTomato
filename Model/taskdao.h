#ifndef TASKDAO_H
#define TASKDAO_H
#include "daobase.h"
#include <memory>
#include <vector>

class QString;
class Project;
class Task;

class TaskDAO : public DaoBase
{
public:
    TaskDAO(QSqlDatabase& database);
    void Init() const override;
    void AddTask(int projectId,Task& task) const;
    void RemoveTask(int id)  const;
    void UpdateTask(const Task& task) const;
    std::unique_ptr<std::vector<std::unique_ptr<Task>>> GetTasksForProject(int projectId) const;
};

#endif // TASKDAO_H
