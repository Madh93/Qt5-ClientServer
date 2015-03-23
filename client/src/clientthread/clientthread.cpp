#include "clientthread.hpp"

ClientThread::ClientThread(FiniteBuffer *finitebuffer, QObject *parent):
    QThread(parent),
    buffer(finitebuffer),
    activo(true) { }


ClientThread::~ClientThread() {

    //Cede turno a otro hilo
    mutex.lock();
        activo = false;
        //cond.wakeOne();
    mutex.unlock();
    wait();
}


void ClientThread::iniciarConexion(const QString &host, quint16 port) {

    QMutexLocker locker(&mutex);
    this->host = host;
    this->port = port;

    // Iniciar comunicación
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

    const int Timeout = 5000;

    // Crear socket y conectar con el servidor
    QTcpSocket socket;
    socket.connectToHost(serverHost, serverPort);

    // Esperar a conectarse
    if (!socket.waitForConnected(Timeout)) {
        emit error(socket.error(), socket.errorString());
        return;
    }

    while (activo) {

        // Extraer imagen
        //QString image = buffer->extractFrame();

        // Enviar saludo inicial
        QString saludo = "Saludo terrícula!";
        //QString saludo = QTime().currentTime().toString();
        //qDebug() << saludo;

        QByteArray datos;
        QDataStream out(&datos, QIODevice::WriteOnly);
        out << (QString)saludo;

        socket.write(datos);
        socket.waitForBytesWritten(Timeout);

    }
        //mutex.lock();
        //    cond.wait(&mutex);
            //serverHost = host;
            //serverPort = port;
//        mutex.unlock();


}
