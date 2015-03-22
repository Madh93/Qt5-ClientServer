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
        explicit Conexion(QString ip = "", quint16 port = 0);
        ~Conexion();

        QString getIp();
        qint16 getPort();
};

#endif // CONEXION_HPP
