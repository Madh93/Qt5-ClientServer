#ifndef CLIENTTHREAD_HPP
#define CLIENTTHREAD_HPP

#include <QTcpSocket>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

#include "finitebuffer.hpp"

class ClientThread : public QThread {

    Q_OBJECT

    private:

        FiniteBuffer *buffer;
        QMutex mutex;
        QWaitCondition cond;
        QString host;
        quint16 port;
        bool activo;
        QTcpSocket socket;

    signals:

        void error(QTcpSocket::SocketError socketError, const QString &message);

    public slots:

        void enviarImagen(QString);

    public:

        ClientThread(FiniteBuffer *finitebuffer, QObject *parent = 0);
        ~ClientThread();

        void iniciarConexion(const QString &host, quint16 port);
        void run();
};

#endif // CLIENTTHREAD_HPP
