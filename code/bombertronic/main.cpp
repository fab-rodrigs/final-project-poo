#include "bombertronic.h"
#include <QtWidgets/QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << "Iniciando jogo...";
    QApplication a(argc, argv);
    Bombertronic w;
    w.show();
    return a.exec();
}
