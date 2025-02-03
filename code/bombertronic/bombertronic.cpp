#include "bombertronic.h"
#include <cstdlib>
#include <ctime>

#include <QGraphicsPixmapItem>
#include <QString>

Bombertronic::Bombertronic(QWidget* parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    Map * map = new Map(scene, 240, 240);
    map->generateMap();

    view->scale(2,2);
    setCentralWidget(view);
    setFixedSize(sizeHint());
}

Bombertronic::~Bombertronic()
{}



