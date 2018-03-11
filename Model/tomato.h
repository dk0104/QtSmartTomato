#ifndef TOMATO_H
#define TOMATO_H
#include <QDateTime>
#include "model_global.h"
#include "states.h"

class MODELSHARED_EXPORT Tomato{
public:
    explicit Tomato();
    int iD() const;
    void setID(int iD);

    int taskId() const;
    void setTaskId(int taskId);

    ProcessStates processState() const;
    void setProcessState(const ProcessStates &processState);

    QDateTime startTime() const;
    void setStartTime(const QDateTime &startTime);

    QDateTime completedTime() const;
    void setCompletedTime(const QDateTime &completedTime);

private:
    QDateTime mStartTime;
    QDateTime mCompletedTime;
    int mID;
    int mTaskId;
    ProcessStates mProcessState;
};

#endif // TOMATO_H
