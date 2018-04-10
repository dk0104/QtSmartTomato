#ifndef TASKDAO_H
#define TASKDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class QString;
class Project;
class Task;

class TaskDAO
{
public:
    TaskDAO(QSqlDatabase& database);
    void Init() const;
    void AddTask(int projectId,Task& task) const;
    void RemoveTask(int id)  const;
    void UpdateTask(const Task& task) const;
    std::unique_ptr<std::vector<std::unique_ptr<Task>>> GetTasksForProject(int projectId) const;
private:
    QSqlDatabase& mDataBase;
};

#endif // TASKDAO_H
