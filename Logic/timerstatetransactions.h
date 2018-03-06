#ifndef TIMERSTATETRANSACTIONS_H
#define TIMERSTATETRANSACTIONS_H

#include <QObject>

class TimerStateTransactions : public QObject
{
    Q_OBJECT
public:
    explicit TimerStateTransactions(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TIMERSTATETRANSACTIONS_H