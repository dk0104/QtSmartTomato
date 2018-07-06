#ifndef TOMATODAO_H
#define TOMATODAO_H

#include "daobase.h"
#include <memory>
#include <vector>

class QString;
class Tomato;

class TomatoDAO : public DaoBase
{
public:
    TomatoDAO(QSqlDatabase& database );
    void Init() const override;
    void AddTomato(Tomato& tomato);
    void RemoveTomato(int id) const;
    void UpdateTomato(const Tomato& tomato) const;
    std::unique_ptr<std::vector<std::unique_ptr<Tomato>>> GetTomatoForTask(int taskId) const;
};

#endif // TOMATODAO_H
