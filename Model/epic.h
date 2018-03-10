#ifndef EPIC_H
#define EPIC_H
#include "model_global.h"
#include <QString>


class MODELSHARED_EXPORT Epic
{
public:
    explicit Epic(const QString& name = "");

    QString name() const;
    void setName(const QString &name);

    int id() const;
    void setId(int id);

public:
    QString mName;
    int mId;
};

#endif // EPIC_H
