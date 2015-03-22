#ifndef CLIENTTHREAD_HPP
#define CLIENTTHREAD_HPP

#include <QThread>
#include <QTcpSocket>

class ClientThread : public QThread {

    Q_OBJECT

    private:

        qintptr socketDescriptor;

    signals:

        void error(QTcpSocket::SocketError socketError);

    public:

        ClientThread(qintptr socket_Descriptor, QObject *parent);
        ~ClientThread();

        void run();
};

#endif // CLIENTTHREAD_HPP
