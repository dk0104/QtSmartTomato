#include "task.h"


QString Task::getName() const
{
    return mName;
}

void Task::setName(const QString &value)
{
    mName = value;
}

int Task::getId() const
{
    return mId;
}

void Task::setId(int id)
{
    mId = id;
}

int Task::getProjectId() const
{
    return mProjectId;
}

void Task::setProjectId(int projectId)
{
    mProjectId = projectId;
}

QString Task::getDescription() const
{
    return mDescription;
}

void Task::setDescription(const QString &description)
{
    mDescription = description;
}

QDateTime Task::getPlanedTime() const
{
    return mPlanedTime;
}

void Task::setPlanedTime(const QDateTime &value)
{
    mPlanedTime = value;
}

int Task::getTomatoCounter() const
{
    return mTomatoCounter;
}

void Task::setTomatoCounter(int tomatoCounter)
{
    mTomatoCounter = tomatoCounter;
}
