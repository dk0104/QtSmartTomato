#include "epic.h"
using namespace std;

Epic::Epic(QObject *parent) : QObject(parent)
{
    projects = make_shared<map<QString,Project>>();

}

std::shared_ptr<map<QString, Project> > Epic::getProjects() const
{
    return projects;
}

void Epic::AddProject(Project &project)
{

}

void Epic::Serialize(const QList<QPair<string, string> > &elementList)
{
    elementList.append(qMakePair("Epic","Test"));

}


