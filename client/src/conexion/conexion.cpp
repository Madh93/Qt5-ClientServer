#include "conexion.hpp"
#include "ui_conexion.h"

Conexion::Conexion(QString user, QString ip, quint16 port) :
    QDialog(0),
    ui(new Ui::Conexion) {

        ui->setupUi(this);
        ui->lineEditUser->setText(user);
        ui->lineEditIP->setText(ip);
        ui->lineEditPort->setText(QString::number(port));
        ui->lineEditPort->setValidator(new QIntValidator(1, 65535, this));
}


Conexion::~Conexion() {

    delete ui;
}


QString Conexion::getUser() {

    return ui->lineEditUser->text();
}


QString Conexion::getIp() {

    return ui->lineEditIP->text();
}


quint16 Conexion::getPort() {

    quint16 port = ui->lineEditPort->text().toInt();
    return port ? port : 0;
}
