#include "server.hpp"

Server::Server(QObject* parent):
    QTcpServer(parent),
    buffer(new FiniteBuffer(20)) { }


Server::~Server() {

}


void Server::insertarImagen(QString img) {

    buffer->insertFrame(img);
}

FiniteBuffer* Server::getBuffer() {

    return buffer;
}


void Server::incomingConnection(qintptr socketDescriptor) {

    qDebug() << "Nueva conexión...";

    ClientThread *client = new ClientThread(socketDescriptor,this);
    connect(client, SIGNAL(finished()), client, SLOT(deleteLater()));
    connect(client, SIGNAL(enviarImagen(QString)),this, SLOT(insertarImagen(QString)));
    client->start();
}

