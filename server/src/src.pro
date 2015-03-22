QT       += core gui \
    multimedia multimediawidgets \
    network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
CONFIG+=ordered
TEMPLATE = app

INCLUDEPATH += $$PWD/acerca \
    $$PWD/capturebuffer \
    $$PWD/dispositivos \
    $$PWD/movie \
    $$PWD/movieplayer \
    $$PWD/slider \
    $$PWD/puerto \
    $$PWD/server

SOURCES += main.cpp\
    acerca/acerca.cpp \
    capturebuffer/capturebuffer.cpp \
    dispositivos/dispositivos.cpp \
    slider/slider.cpp \
    movie/movie.cpp \
    movieplayer/movieplayer.cpp \
    puerto/puerto.cpp \
    server/server.cpp

HEADERS  += base.hpp \
    acerca/acerca.hpp \
    capturebuffer/capturebuffer.hpp \
    dispositivos/dispositivos.hpp \
    slider/slider.hpp \
    movie/movie.hpp \
    movieplayer/movieplayer.hpp \
    puerto/puerto.hpp \
    server/server.hpp

FORMS    += acerca/acerca.ui \
    dispositivos/dispositivos.ui \
    movieplayer/movieplayer.ui \
    puerto/puerto.ui
