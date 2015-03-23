#include "clientthread.hpp"

ClientThread::ClientThread(qintptr socket_Descriptor, QObject *parent):
    QThread(parent),
    socketDescriptor(socket_Descriptor),
    socket(NULL),
    activo(true) { }


ClientThread::~ClientThread() {

    mutex.lock();
        activo = false;
        delete socket;
    mutex.unlock();
    wait();
}

void ClientThread::disconnected() {

    qDebug() << socketDescriptor << " se ha desconectado...";
    socket->deleteLater();
    //exit(0);
}


void ClientThread::run() {

    socket = new QTcpSocket;

    //Inicializarlo con el descriptor del hilo
    if (!socket->setSocketDescriptor(socketDescriptor)) {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << socketDescriptor << " se ha conectado...";

    while(activo){

        imagen = "";
        socket->waitForReadyRead(-1);
        QByteArray datos = socket->readAll();
        QDataStream in(datos);
        in >> imagen;

        //if (imagen != "")
          //  qDebug() << imagen;
    }

    qDebug() << "terminando hilo...";
    //socket->disconnectFromHost();
    //socke->waitForDisconnected();
}
