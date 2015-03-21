#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <QMovie>
#include <QFile>
#include <QFileInfo>


class Movie : public QMovie {

    private:

        QFileInfo *info;

    public:

        Movie(QObject *parent = 0);
        ~Movie();

        void setFileName(const QString &ruta);

        // Informacion
        QString path();         // /home/migue/Escritorio/movie.gif
        QString name();         // movie.gif
        QString baseName();     // movie
        QString extension();    // .gif
        QString directory();    // /home/migue/Escritorio/
        qint64 size();          // 10485760 (Bytes)

};

#endif // MOVIE_HPP
