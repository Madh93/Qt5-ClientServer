#include "finitebuffer.hpp"

FiniteBuffer::FiniteBuffer(int size) :
    bufferSize(size),
    count(0),
    buffer(new QString [bufferSize]){ }


FiniteBuffer::~FiniteBuffer() {

    if (buffer) {
        delete [] buffer;
        buffer = NULL;
    }

}


void FiniteBuffer::insertFrame(const QString& frame) {

    static int i = -1;      // Posición último frame insertado
    mutex.lock();          // Bloquear el cerrojo
                            // El código del productor a partir de este punto y hasta
                            // el unlock() no se ejecutará si el consumidor ha bloqueado el
                            // cerrojo primero.

    if (count == bufferSize)                    // ¿Cola llena?
        bufferNotFull.wait(&mutex);             // Dormir hasta que haya sitio
                                                // en la cola.
                                                // Insertar el frame en la cola
    buffer[++i % bufferSize] = frame;
    ++count;
    bufferNotEmpty.wakeAll();                   // Despertar al consumidor si
                                                // esperaba por más frames.
    mutex.unlock();        // Liberar el cerrojo
}


QString FiniteBuffer::extractFrame() {

    static int i = -1;      // Posición último frame extraido

    mutex.lock();           // Bloqueamos el cerrojo
                            // El código del consumidor a partir de este punto y
                            // hasta el unlock() no se ejecutará si el productor ha
                            // bloqueado el cerrojo primero.

    if (count == 0)                     // ¿Cola vacía?...
    bufferNotEmpty.wait(&mutex);        // Dormir si es así

    QString image = buffer[++i % bufferSize];

    --count;
    bufferNotFull.wakeAll();    // Despertar al productor si
                                // esperaba por un hueco.

    mutex.unlock();        // Liberar el cerrojo

    return image;

}
