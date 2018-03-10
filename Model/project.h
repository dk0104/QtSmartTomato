#ifndef PROJECT_H
#define PROJECT_H

#include "states.h"
#include "serializer.h"

#include <QObject>

class Project : public QObject, Serializer
{
    Q_OBJECT
public:
    explicit Project(QObject *parent = nullptr);

signals:
   void NotifyProjectChange(QDateTime date);

public slots:
protected:
private:
   QString name;
   QDateTime creationDate;
   ProcessStates currentState;
   std::shared_ptr<QList<Task>> tasks;


   // Serializer interface
public:
   QDomElement SerializeToDomElement(QDomElement &document);
};

#endif // PROJECT_H
