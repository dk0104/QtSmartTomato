#include "taskmodel.h"
#include "projectmodel.h"
#include "taskdao.h"

using namespace std;

TaskModel::TaskModel(const ProjectModel& projectModel, QObject* parent ):
    QAbstractListModel (parent),
    mProjectId(-1),
    mDataBaseConnector(DataBaseConnector::GetInstance()),
    mTasks(new vector<unique_ptr<Task>>())
{

    connect(&projectModel,&ProjectModel::rowsRemoved,this,&TaskModel::deleteTasksForProjects);
}

int TaskModel::rowCount(const QModelIndex &parent) const
{
    return mTasks->size();
}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index)){
        return QVariant();
    }
    const Task& task = *mTasks->at(index.row());
    switch (role) {
        case NameRole:
            return task.getName();
        case DisplayRole:
            return task.getDescription();
    default:
        return QVariant();
    }
}

bool TaskModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0
        || row >= rowCount()
        || count < 0
        || (row+count) > rowCount()){
        return false;
    }
    beginRemoveRows(parent,row,row+count-1);
    int countLeft=count;
    while(countLeft--){
        const Task& task = *mTasks->at(row+countLeft);
        auto taskDaoPtr = GetTaskDao();
        taskDaoPtr->RemoveTask(task.getId());
    }
    mTasks->erase(mTasks->begin()+row,mTasks->begin()+row+count);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> TaskModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[DisplayRole]="display";
    return roles;
}

void TaskModel::setProjectId(int projectId)
{
    beginResetModel();
    mProjectId=projectId;
    loadTask(mProjectId);
    endResetModel();
}

void TaskModel::loadTask(int projectID)
{
    if(mProjectId <= 0){
        mTasks.reset(new vector<unique_ptr<Task>>());
        return;
    } 
    auto taskPtr = GetTaskDao();
    mTasks = taskPtr->GetTasksForProject(mProjectId);
}

TaskDAO* TaskModel::GetTaskDao(){
    auto taskDao = mDataBaseConnector.GetDaoBaseList()[TASK];
    auto taskDaoPtr = dynamic_cast<TaskDAO*>(taskDao);
    return taskDaoPtr;
}
