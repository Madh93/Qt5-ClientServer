#include "server.hpp"

Server::Server(QObject* parent):
    QTcpServer(parent) {

}


Server::~Server() {

}


void Server::transmitirImagen(QString imagen) {

    emit recibirImagen(imagen);
}


void Server::incomingConnection(qintptr socketDescriptor) {

    qDebug() << "Nueva conexión...";

    ClientThread *client = new ClientThread(socketDescriptor,this);
    connect(client, SIGNAL(finished()), client, SLOT(deleteLater()));
    connect(client, SIGNAL(recibirImagen(QString)), this, SLOT(transmitirImagen(QString)));
    client->start();
}

