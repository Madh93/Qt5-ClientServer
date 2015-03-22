#ifndef SERVER_HPP
#define SERVER_HPP

#include <QTcpServer>

class Server : public QTcpServer {

    Q_OBJECT

    public:

        explicit Server(QObject *parent = 0);
        ~Server();

    protected:

        void incomingConnection(qintptr socketDescriptor);
};

#endif // SERVER_HPP
