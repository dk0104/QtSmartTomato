#ifndef EPICMODEL_H
#define EPICMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "epic.h"
#include "databaseconnector.h"

class MODELSHARED_EXPORT EpicModel:public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{
        IdRole = Qt::UserRole+1,
        NameRole
    };

    EpicModel(QObject* parent = nullptr);
    QHash<int, QByteArray>  roleNames() const;

private:
    DataBaseConnector& mDataBaseConnector;
    std::unique_ptr<std::vector<std::unique_ptr<Epic>>> mEpics;
};

#endif // EPICMODEL_H
