#ifndef TOMATODAO_H
#define TOMATODAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class QString;
class Tomato;

class TomatoDAO
{
public:
    TomatoDAO(QSqlDatabase& database );
    void Init() const;
    void AddTomato(int taskId,Tomato& tomato);
    void RemoveTomato(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Tomato>>> GetTomatoForTask(int taskId) const;
private:
    QSqlDatabase& mDataBase;
};

#endif // TOMATODAO_H
