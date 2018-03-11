#include "tomato.h"


int Tomato::iD() const
{
    return mID;
}

void Tomato::setID(int iD)
{
    mID = iD;
}

int Tomato::taskId() const
{
    return mTaskId;
}

void Tomato::setTaskId(int taskId)
{
    mTaskId = taskId;
}

ProcessStates Tomato::processState() const
{
    return mProcessState;
}

void Tomato::setProcessState(const ProcessStates &processState)
{
    mProcessState = processState;
}

QDateTime Tomato::startTime() const
{
    return mStartTime;
}

void Tomato::setStartTime(const QDateTime &startTime)
{
    mStartTime = startTime;
}

QDateTime Tomato::completedTime() const
{
    return mCompletedTime;
}

void Tomato::setCompletedTime(const QDateTime &completedTime)
{
    mCompletedTime = completedTime;
}
