#include "epic.h"
using namespace std;


Epic::Epic(const QString &name):
    mName(name),
    mId(-1)
{
}

QString Epic::name() const
{
    return mName;
}

void Epic::setName(const QString &name)
{
    mName = name;
}

int Epic::id() const
{
    return mId;
}

void Epic::setId(int id)
{
    mId = id;
}



