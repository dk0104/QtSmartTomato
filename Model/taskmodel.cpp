#include "taskmodel.h"
#include "projectmodel.h"

using namespace std;

TaskModel::TaskModel(const ProjectModel& projectModel, QObject* parent ):
    QAbstractListModel (parent),
    mDataBaseConnector(DataBaseConnector::GetInstance()),
    mTaskId(-1),
    mTasks(new vector<unique_ptr<Task>>())
{
    connect(&projectModel,&ProjectModel::rowsRemoved,this,&TaskModel::deleteTasksForProjects);
}

int TaskModel::rowCount(const QModelIndex &parent) const
{

}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{

}

bool TaskModel::removeRows(int row, int count, const QModelIndex &parent)
{

}

QHash<int, QByteArray> TaskModel::roleNames() const
{

}

void TaskModel::setTaskId(int taskId)
{
    beginResetModel();
    mTaskId=taskId;
    loadTask(mTaskId);
    endResetModel();
}
