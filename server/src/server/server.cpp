#include "server.hpp"

Server::Server(QObject* parent):
    QTcpServer(parent) {

}


Server::~Server() {

}


void Server::incomingConnection(qintptr socketDescriptor) {

    qDebug() << "Nueva conexión...";

    ClientThread *client = new ClientThread(socketDescriptor,this);
    connect(client, SIGNAL(finished()), client, SLOT(deleteLater()));
    client->start();
}

