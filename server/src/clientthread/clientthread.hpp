#ifndef CLIENTTHREAD_HPP
#define CLIENTTHREAD_HPP

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class ClientThread : public QThread {

    Q_OBJECT

    private:

        qintptr socketDescriptor;
        QTcpSocket *socket;

    signals:

        void error(QTcpSocket::SocketError socketError);

    public slots:

        void disconnected();

    public:

        ClientThread(qintptr socket_Descriptor, QObject *parent);
        ~ClientThread();

        void run();
};

#endif // CLIENTTHREAD_HPP
