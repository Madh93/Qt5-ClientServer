#include "conexion.hpp"
#include "ui_conexion.h"

Conexion::Conexion(QString ip, quint16 port) :
    QDialog(0),
    ui(new Ui::Conexion) {

        ui->setupUi(this);
        ui->lineEditIP->setText(ip);
        ui->lineEditPort->setText(QString::number(port));
}


Conexion::~Conexion() {

    delete ui;
}


QString Conexion::getIp() {

    return ui->lineEditIP->text();
}


qint16 Conexion::getPort() {

    qint16 port = ui->lineEditPort->text().toInt();
    return port ? port : 0;
}
