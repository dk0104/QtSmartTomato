#include "project.h"

Project::Project()
{

}

QString Project::getName() const
{
    return name;
}

void Project::setName(const QString &value)
{
    name = value;
}

ProcessStates Project::getCurrentState() const
{
    return currentState;
}

void Project::setCurrentState(const ProcessStates &value)
{
    currentState = value;
}

int Project::getId() const
{
    return mId;
}

void Project::setId(int id)
{
    mId = id;
}
