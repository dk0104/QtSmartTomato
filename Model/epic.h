#ifndef EPIC_H
#define EPIC_H
#include "states.h"


#include <QObject>

class Epic : public QObject
{
    Q_OBJECT
public:
    explicit Epic(QObject *parent = nullptr);

    std::shared_ptr<map<QString, Project> > getProjects() const;

    void AddProject(Project& project);


signals:


public slots:

protected:

    std::shared_ptr<map<QString,Project>> projects;
};

#endif // EPIC_H
