#include "projectmodel.h"
#include "projectdao.h"


ProjectModel::ProjectModel(QObject *parent):
    QAbstractListModel(parent),
    mDataBaseConnector(DataBaseConnector::GetInstance())
{
    auto projectsDAO = mDataBaseConnector.GetDaoBaseList()[PROJECT];
    auto pp = dynamic_cast<ProjectDAO*>(projectsDAO);
    mProjects = pp->GetProjects();
}

int ProjectModel::rowCount(const QModelIndex &parent) const
{
    return mProjects->size();
}

QVariant ProjectModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index)){
        return QVariant;
    }
    const Project& project = mProjects->at(index.row);
    switch (role) {
    case Roles::IdRole:
        return project.getId();
    case Roles::NameRole:
    case Qt::DisplayRole:
        return project.getName();

    default:
        return QVariant;
    }

}

bool ProjectModel::removeRows(int row, int count, const QModelIndex &parent)
{

}

QHash<int, QByteArray> ProjectModel::roleNames() const
{

}

bool ProjectModel::isIndexValid(const QModelIndex &index) const
{

}
