#include "bombertronic.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bombertronic w;
    w.show();
    return a.exec();
}
