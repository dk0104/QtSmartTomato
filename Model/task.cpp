#include "task.h"


Task::Task()
{

}

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

QDate Task::getPlanedTime() const
{
    return mPlannedTime;
}

void Task::setPlanedTime(const QDate &value)
{
    mPlannedTime = value;
}

int Task::getTomatoCounter() const
{
    return mTomatoCounter;
}

void Task::setTomatoCounter(int tomatoCounter)
{
    mTomatoCounter = tomatoCounter;
}
