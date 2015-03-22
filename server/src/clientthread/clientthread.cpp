#include "clientthread.hpp"

ClientThread::ClientThread(qintptr socket_Descriptor, QObject *parent):
    QThread(parent),
    socketDescriptor(socket_Descriptor) { }


ClientThread::~ClientThread() {

}

void ClientThread::disconnected() {

    qDebug() << socketDescriptor << " se ha desconectado...";
    socket->deleteLater();
    //exit(0);
}


void ClientThread::run() {

    socket = new QTcpSocket;
    //QTcpSocket socket;

    //Inicializarlo con el descriptor del hilo
    if (!socket->setSocketDescriptor(socketDescriptor)) {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    //connect(&socket, SIGNAL(disconnected()), &socket, SLOT(deleteLater()));

    qDebug() << socketDescriptor << " se ha conectado...";

    /*
    socket.write(dataOut);
    socket.waitForBytesWritten();
    socket.waitForReadyRead(-1);
    QByteArray dataInt = socket.readAll();
    //...procesar datos recibidos en dataINT

    socket.disconnectFromHost();
    socket.waitForDisconnected();
    */
}

