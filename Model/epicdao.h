#ifndef EPICDAO_H
#define EPICDAO_H

#include "daobase.h"

class EpicDAO : public DaoBase
{
public:
    EpicDAO(QSqlDatabase& db);
    void Init() const override;
};

#endif // EPICDAO_H
