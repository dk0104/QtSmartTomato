#ifndef EPICDAO_H
#define EPICDAO_H

class SqlDatabase;
class EpicDAO
{
public:
    EpicDAO(QSqlDatabase& database);
    void init() const;
private:
    QSqlDatabase& mDatabase;
};

#endif // EPICDAO_H
