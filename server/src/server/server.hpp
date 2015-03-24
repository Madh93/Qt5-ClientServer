#ifndef SERVER_HPP
#define SERVER_HPP

#include <QTcpServer>
#include "clientthread.hpp"
#include "finitebuffer.hpp"

class Server : public QTcpServer {

    Q_OBJECT


    private:

        FiniteBuffer *buffer;

    public slots:

        void insertarImagen(QString img);

    public:

        explicit Server(QObject *parent = 0);
        ~Server();

        FiniteBuffer* getBuffer();

    protected:

        void incomingConnection(qintptr socketDescriptor);
};

#endif // SERVER_HPP
