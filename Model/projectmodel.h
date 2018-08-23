#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "project.h"
#include "databaseconnector.h"

class MODELSHARED_EXPORT ProjectModel:public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{
        IdRole = Qt::UserRole+1,
        NameRole
    };

    ProjectModel(QObject* parent = nullptr);
    QModelIndex addProject(const Project& project);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool removeRows(int row, int count, const QModelIndex &parent);
    QHash<int, QByteArray> roleNames() const;

private:
    bool isIndexValid(const QModelIndex& index) const;
    DataBaseConnector& mDataBaseConnector;
    std::unique_ptr<std::vector<std::unique_ptr<Project>>> mProjects;
};

#endif // PROJECTMODEL_H
