#ifndef MOVIEPLAYER_HPP
#define MOVIEPLAYER_HPP

#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>
#include <QProcess>
#include <QSettings>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QPainter>
#include <QTime>
#include <QTcpSocket>

#include "base.hpp"
#include "movie.hpp"
#include "capturebuffer.hpp"
#include "slider.hpp"
#include "dispositivos.hpp"
#include "acerca.hpp"
#include "conexion.hpp"
#include "clientthread.hpp"


namespace Ui {
    class MoviePlayer;
}

class MoviePlayer : public QMainWindow {

    Q_OBJECT

    private:

        Ui::MoviePlayer *ui;
        int speed;
        Movie *movie;
        QCamera *camara;
        CaptureBuffer *captureBuffer;
        ClientThread *socket;
        FiniteBuffer *finiteBuffer;
        QLabel *label;
        QLabel velocidad, tiempo;
        Slider slider;
        QSettings preferencias;
        QPixmap pixmap;

        void crearLabel();
        void limpiarMovie();
        void limpiarCamara();
        void limpiarSocket();
        void activarFuncionalidades(bool cond);
        void updateVelocidad();
        void conectarConServidor();

    private slots:

        void setFrameSlider(int frame);
        void updateFrameSlider();
        void showFrame();
        void updateImagen(QImage imagen);

        // Archivo
        void on_actionAbrir_triggered();
        void on_actionCapturarVideo_triggered();
        void on_actionCerrar_triggered();
        void on_actionSalir_triggered();

        // Editar
        void on_actionAbrirCon_triggered();
        void on_actionAbrirDirectorio_triggered();
        void on_actionAbrirTerminal_triggered();
        void on_actionRenombrar_triggered();
        void on_actionEliminar_triggered();

        // Reproducción
        void on_actionReproducir_triggered();
        void on_actionPausar_triggered();
        void on_actionDetener_triggered();
        void on_actionAvanzar_triggered();
        void on_actionRetroceder_triggered();
        void on_actionSiguienteFotograma_triggered();
        void on_actionAnteriorFotograma_triggered();
        void on_actionNormal_triggered();
        void on_actionIncrementar_triggered();
        void on_actionReducir_triggered();
        void on_actionDoblar_triggered();
        void on_actionMitad_triggered();

        // Herramientas
        void on_actionCapturarPantalla_triggered();
        void on_actionAjustarVentana_toggled(bool cond);
        void on_actionActivarCache_toggled(bool cond);

        // Preferencias
        void on_actionConfigurarConexion_triggered();
        void on_actionDispositivos_triggered();
        void on_actionAutoReproducir_toggled(bool cond);
        void on_actionPantallaCompleta_toggled(bool cond);

        // Ayuda
        void on_actionAyuda_triggered();
        void on_actionAcercaDe_triggered();
        void on_actionAcercaDeQt_triggered();

    public:

        explicit MoviePlayer(QWidget *parent = 0);
        ~MoviePlayer();
};

#endif // MOVIEPLAYER_HPP
