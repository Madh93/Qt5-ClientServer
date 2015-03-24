#ifndef CONEXION_HPP
#define CONEXION_HPP

#include <QDialog>

namespace Ui {
    class Conexion;
}

class Conexion : public QDialog {

    Q_OBJECT

    private:
        Ui::Conexion *ui;

    public:
        explicit Conexion(QString user = "", QString ip = "", quint16 port = 0);
        ~Conexion();

        QString getUser();
        QString getIp();
        quint16 getPort();
};

#endif // CONEXION_HPP
