#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>

class Project : public QObject
{
    Q_OBJECT
public:
    explicit Project(QObject *parent = nullptr);

signals:
   void NotifyProjectChange(QDateTime date);

public slots:
protected:
private:

};

#endif // PROJECT_H
