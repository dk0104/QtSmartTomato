#ifndef DAOBASE_H
#define DAOBASE_H

class QSqlDatabase;
class DaoBase
{
public:
    explicit DaoBase(QSqlDatabase& database);
    virtual void Init() const = 0;
protected:
    QSqlDatabase& mDataBaseRef;
};


#endif // DAOBASE_H
