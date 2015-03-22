#ifndef CLIENTTHREAD_HPP
#define CLIENTTHREAD_HPP

#include <QTcpSocket>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

class ClientThread : public QThread {

    Q_OBJECT

    private:

        QMutex mutex;
        QWaitCondition cond;

    signals:

        void error(QTcpSocket::SocketError socketError);

    public:
        ClientThread(QObject *parent = 0);
        ~ClientThread();

        void run();
};

#endif // CLIENTTHREAD_HPP
