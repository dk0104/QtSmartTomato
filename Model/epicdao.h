#ifndef EPICDAO_H
#define EPICDAO_H

#include "daobase.h"
#include "epic.h"

class EpicDAO : public DaoBase
{
public:
    EpicDAO(QSqlDatabase& db);
    virtual ~EpicDAO();
    void Init() const override;
    unique_ptr<Epic> GetEpic(int id = 1);
};

#endif // EPICDAO_H
