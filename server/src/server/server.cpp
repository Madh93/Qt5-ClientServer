#include "server.hpp"

Server::Server(QObject* parent):
    QTcpServer(parent) {

}


Server::~Server() {

}


void Server::incomingConnection(qintptr socketDescriptor) {

}

