#ifndef TASK_H
#define TASK_H
#include "model_global.h"
#include <QString>
#include <QDateTime>

class MODELSHARED_EXPORT Task {
public:

    explicit Task();
    QString getName() const;
    void setName(const QString &value);

    int getId() const;
    void setId(int id);

    int getProjectId() const;
    void setProjectId(int projectId);

    QString getDescription() const;
    void setDescription(const QString &description);

    QDateTime getPlanedTime() const;
    void setPlanedTime(const QDateTime &value);

    int getTomatoCounter() const;
    void setTomatoCounter(int tomatoCounter);

private:
    int mId;
    int mProjectId;
    QString mName;
    QString mDescription;
    QDateTime mPlanedTime;
    int mTomatoCounter;
};

#endif // TASK_H
