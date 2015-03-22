#include "clientthread.hpp"

ClientThread::ClientThread(qintptr socket_Descriptor, QObject *parent):
    QThread(parent),
    socketDescriptor(socket_Descriptor) { }


ClientThread::~ClientThread() {

}


void ClientThread::run() {

    QTcpSocket socket;

    //Inicializarlo con el descriptor del hilo
    if (!socket.setSocketDescriptor(socketDescriptor)) {
        emit error(socket.error());
        return;
    }

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

