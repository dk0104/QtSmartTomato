#include "epicmodel.h"
#include "epicdao.h"

using namespace std;

EpicModel::EpicModel(QObject *parent):
    QAbstractListModel(parent),
    mDataBaseConnector(DataBaseConnector::GetInstance())
{
    auto epicDAO = mDataBaseConnector.GetDaoBaseList()[EPIC];
    auto pp = dynamic_cast<EpicDAO*>(epicDAO);

}

