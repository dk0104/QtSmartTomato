#ifndef TOMATO_H
#define TOMATO_H

#include <QObject>

class Tomato : public QObject
{
    Q_OBJECT
public:
    explicit Tomato(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TOMATO_H