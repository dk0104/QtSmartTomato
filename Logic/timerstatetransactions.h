#ifndef TIMERSTATETRANSACTIONS_H
#define TIMERSTATETRANSACTIONS_H
#include <QTime>

//#include <../Model/tomato.h>

#include <QObject>

class TimerStateTransactions : public QObject
{
    Q_OBJECT

    //Q_PROPERTY(Tomato Tomato READ Tomato WRITE setTomato NOTIFY TomatoChanged)
    //Tomato m_Tomato;

public:
    explicit TimerStateTransactions(QObject *parent = nullptr);
    void setTomato();
    void StartTomato();
    void PauseTomato();
    void CancelTomato();
    //Tomato Tomato() const;

signals:
    //void TomatoChanged(QTime time);

public slots:

};

#endif // TIMERSTATETRANSACTIONS_H
