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
    void AddTomato(Tomato& tomato);
    void RemoveTomato(int id) const;
    void UpdateTomato(const Tomato& tomato) const;
    std::unique_ptr<std::vector<std::unique_ptr<Tomato>>> GetTomatoForTask(int taskId) const;
private:
    QSqlDatabase& mDataBase;
};

#endif // TOMATODAO_H
