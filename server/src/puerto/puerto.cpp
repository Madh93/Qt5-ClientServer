#include "puerto.hpp"
#include "ui_puerto.h"

Puerto::Puerto(quint16 current) :
    QDialog(0),
    ui(new Ui::Puerto) {

        ui->setupUi(this);
        ui->lineEdit->setText(QString::number(current));
}


Puerto::~Puerto() {

    delete ui;
}


quint16 Puerto::getPort() {

    qint16 port = ui->lineEdit->text().toInt();
    return port ? port : 0;
}
