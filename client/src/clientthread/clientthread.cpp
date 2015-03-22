#include "clientthread.hpp"

ClientThread::ClientThread(QObject* parent):
    QThread(parent),
    activo(true) { }


ClientThread::~ClientThread() {

    //Cede turno a otro hilo
    mutex.lock();
        activo = false;
        cond.wakeOne();
    mutex.unlock();
    wait();
}


void ClientThread::enviarImagen(QString img) {

    QByteArray datos;
    QDataStream out(&datos, QIODevice::WriteOnly);
    out << (QString)img;

    socket.write(datos);
    socket.waitForBytesWritten();
}


void ClientThread::iniciarConexion(const QString &host, quint16 port) {

    QMutexLocker locker(&mutex);
    this->host = host;
    this->port = port;

    // Iniciar comunicación o ceder el turno
    if (!isRunning())
        start();
    else
        cond.wakeOne();
}


void ClientThread::run() {

    mutex.lock();
        QString serverHost = host;
        quint16 serverPort = port;
    mutex.unlock();

    while (activo) {

        const int Timeout = 5000;

        // Crear socket y conectar con el servidor
        //QTcpSocket socket;
        socket.connectToHost(serverHost, serverPort);

        // Esperar a conectarse
        if (!socket.waitForConnected(Timeout)) {
            emit error(socket.error(), socket.errorString());
            return;
        }

        // Enviar saludo inicial
        QString saludo = "Saludo terrícula!";

        QByteArray datos;
        QDataStream out(&datos, QIODevice::WriteOnly);
        out << (QString)saludo;

        socket.write(datos);
        socket.waitForBytesWritten();


        mutex.lock();
            cond.wait(&mutex);
            serverHost = host;
            serverPort = port;
        mutex.unlock();
    }


}
