#include "projectmodel.h"


ProjectModel::ProjectModel(QPbject *parent):
    QAbstractListModel(parent),
    mDataBaseConnector(DataBaseConnector::GetInstance()),
    mProjects(mDataBaseConnector.mDaoBaseList[PROJECT]-> )
{

}

int ProjectModel::rowCount(const QModelIndex &parent) const
{

}

QVariant ProjectModel::data(const QModelIndex &index, int role) const
{

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
