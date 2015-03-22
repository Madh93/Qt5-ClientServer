#ifndef PUERTO_HPP
#define PUERTO_HPP

#include <QDialog>

namespace Ui {
    class Puerto;
}

class Puerto : public QDialog {

    Q_OBJECT

    private:
        Ui::Puerto *ui;

    public:
        explicit Puerto(quint16 current = 0);
        ~Puerto();

        quint16 getPort();
};

#endif // PUERTO_HPP
