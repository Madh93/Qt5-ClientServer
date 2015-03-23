#ifndef CLIENTTHREAD_HPP
#define CLIENTTHREAD_HPP

#include <QTcpSocket>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>
#include <QTime>

#include "finitebuffer.hpp"

class ClientThread : public QThread {

    Q_OBJECT

    private:

        FiniteBuffer *buffer;
        QMutex mutex;
        QWaitCondition cond;
        QString host;
        quint16 port;
        bool activo;

    signals:

        void error(QTcpSocket::SocketError socketError, const QString &message);

    public:

        ClientThread(FiniteBuffer *finitebuffer, QObject *parent = 0);
        ~ClientThread();

        void iniciarConexion(const QString &host, quint16 port);
        void run();
};

#endif // CLIENTTHREAD_HPP
