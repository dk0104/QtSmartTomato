#include "projectmodel.h"
#include "projectdao.h"
using namespace std;

ProjectModel::ProjectModel(QObject *parent):
    QAbstractListModel(parent),
    mDataBaseConnector(DataBaseConnector::GetInstance())
{
    auto projectsDAO = mDataBaseConnector.GetDaoBaseList()[PROJECT];
    auto pp = dynamic_cast<ProjectDAO*>(projectsDAO);
    mProjects = pp->GetProjects();
}

QModelIndex ProjectModel::addProject(const Project &project)
{
    auto rowIndex = rowCount();
    beginInsertRows(QModelIndex(),rowIndex,rowIndex);
    unique_ptr<Project> newProject(new Project(project));
    auto tmpProjectDao = dynamic_cast<ProjectDAO*>(mDataBaseConnector.GetDaoBaseList()[PROJECT]);
    tmpProjectDao->AddProject(*newProject);
    mProjects->push_back(move(newProject));
    endInsertRows();
    return index(rowIndex,0);
}

int ProjectModel::rowCount(const QModelIndex &parent) const
{
    return mProjects->size();
}

QVariant ProjectModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index)){
        return QVariant();
    }
    auto project = *mProjects->at(index.row());
    switch (role) {
    case Roles::IdRole:
        return project.getId();
    case Roles::NameRole:
    case Qt::DisplayRole:
        return project.getName();
    default:
        return QVariant();
    }
}

bool ProjectModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!isIndexValid(index) || role != Roles::NameRole)
    {
        return false;
    }

    Project& project = *mProjects->at(index.row());
    project.setName(value.toString());
    auto tmpProjectDao = dynamic_cast<ProjectDAO*>(mDataBaseConnector.GetDaoBaseList()[PROJECT]);
    tmpProjectDao->UpdateProject(project);
    emit dataChanged(index,index);
    return true;
}

bool ProjectModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0
            || row >= rowCount()
            || count < 0
            || (row+count) > rowCount()){
        return false;
    }
    beginRemoveRows(parent,row,row+count-1);
    int countLeft = count;
    while(countLeft--){
        const Project& project = *mProjects->at(row+countLeft);
        auto tmpProjectDao = dynamic_cast<ProjectDAO*>(mDataBaseConnector.GetDaoBaseList()[PROJECT]);
        tmpProjectDao->RemoveProject(project.getId());
    }
    mProjects->erase(mProjects->begin() + row, mProjects->begin() + row + count);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> ProjectModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

bool ProjectModel::isIndexValid(const QModelIndex &index) const
{

}
