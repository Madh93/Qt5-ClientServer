#ifndef FINITEBUFFER_H
#define FINITEBUFFER_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

class FiniteBuffer : public QObject {

    Q_OBJECT

    private:

        const int bufferSize; // Tamaño de la cola
        int count; // Contador de frames en la cola
        QString* buffer; // Cola de frames como array de C

        // Objetos de sincronización
        QWaitCondition bufferNotEmpty;
        QWaitCondition bufferNotFull;
        QMutex mutex;

    public:

        FiniteBuffer(int size);
        ~FiniteBuffer();

        // Métodos de inserción y extracción para el productor y el
        // consumidor, respectivamente
        void insertFrame(const QString& frame);
        QString extractFrame();
};

#endif // FINITEBUFFER_H
