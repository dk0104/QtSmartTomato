#ifndef EPICDAO_H
#define EPICDAO_H

class QSqlDatabase;
class Project;

class EpicDAO
{
public:
    EpicDAO(QSqlDatabase& database);
    void init() const;
private:
    QSqlDatabase& mDatabase;
};

#endif // EPICDAO_H
