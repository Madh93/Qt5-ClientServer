#ifndef CLIENTTHREAD_HPP
#define CLIENTTHREAD_HPP

#include <QThread>
#include <QMutex>
#include <QTcpSocket>
#include <QDebug>

#include "finitebuffer.hpp"

class ClientThread : public QThread {

    Q_OBJECT

    private:

        FiniteBuffer *buffer;
        qintptr socketDescriptor;
        QTcpSocket *socket;
        QString imagen;
        QMutex mutex;
        bool activo;

    signals:

        void error(QTcpSocket::SocketError socketError);
        void enviarImagen(QString);

    public slots:

        void disconnected();

    public:

        ClientThread(qintptr socket_Descriptor, QObject *parent);
        ~ClientThread();

        void run();
};

#endif // CLIENTTHREAD_HPP
