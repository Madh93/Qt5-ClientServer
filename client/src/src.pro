QT       += core gui \
    multimedia multimediawidgets \
    network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
CONFIG+=ordered
TEMPLATE = app

INCLUDEPATH += $$PWD/acerca \
    $$PWD/capturebuffer \
    $$PWD/dispositivos \
    $$PWD/movie \
    $$PWD/movieplayer \
    $$PWD/slider \
    $$PWD/conexion \
    $$PWD/clientthread

SOURCES += main.cpp\
    acerca/acerca.cpp \
    capturebuffer/capturebuffer.cpp \
    dispositivos/dispositivos.cpp \
    slider/slider.cpp \
    movie/movie.cpp \
    movieplayer/movieplayer.cpp \
    conexion/conexion.cpp \
    clientthread/clientthread.cpp

HEADERS  += base.hpp \
    acerca/acerca.hpp \
    capturebuffer/capturebuffer.hpp \
    dispositivos/dispositivos.hpp \
    slider/slider.hpp \
    movie/movie.hpp \
    movieplayer/movieplayer.hpp \
    conexion/conexion.hpp \
    clientthread/clientthread.hpp

FORMS    += acerca/acerca.ui \
    dispositivos/dispositivos.ui \
    movieplayer/movieplayer.ui \
    conexion/conexion.ui
