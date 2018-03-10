#ifndef EPIC_H
#define EPIC_H
#include "model_global.h"
#include "states.h"
#include "serializer.h"

#include <QObject>

class MODELSHARED_EXPORT Epic : public QObject, Serializer
{
public:
    explicit Epic(QObject *parent = nullptr);

    std::shared_ptr<QList<Project> > getProjects() const;

    void AddProject(Project& project);
protected:

    std::shared_ptr<QList<Project>> projects;


    // Serializer interface
public:
    void Serialize(const QList<QPair<string,string>>& elementList) override;
};

#endif // EPIC_H
