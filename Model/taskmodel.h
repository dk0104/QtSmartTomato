#ifndef TASKMODEL_H
#define TASKMODEL_H

#include "databaseconnector.h"
#include <QAbstractListModel>
#include "task.h"
#include <QObject>

class ProjectModel;
class TaskDAO;

class MODELSHARED_EXPORT TaskModel: public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles{
        IdRole = Qt::UserRole+1,
        DisplayRole,
        NameRole
    };

    TaskModel(const ProjectModel& projectModel, QObject* parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool removeRows(int row, int count, const QModelIndex &parent);
    QHash<int, QByteArray> roleNames() const;

    void setProjectId(int projectId);
    void clearTask();

public slots:
    void deleteTasksForProjects();

private:
    void loadTask(int taskID);
    bool isIndexValid(const QModelIndex& index) const;
    TaskDAO *GetTaskDao();

    int mProjectId;
    DataBaseConnector& mDataBaseConnector;
    std::unique_ptr<std::vector<std::unique_ptr<Task>>> mTasks;
};

#endif // TASKMODEL_H
