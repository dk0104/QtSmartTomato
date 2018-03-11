#ifndef PROJECT_H
#define PROJECT_H
#include "model_global.h"
#include "states.h"
#include <QDateTime>


class MODELSHARED_EXPORT Project
{
public:
    explicit Project();

    QString getName() const;
    void setName(const QString &value);

    ProcessStates getCurrentState() const;
    void setCurrentState(const ProcessStates &value);

    int getId() const;
    void setId(int id);

protected:
private:
    int mId;
    QString name;
    QDateTime creationDate;
    ProcessStates currentState;
};

#endif // PROJECT_H
