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

    Obstacle *obstacle = new Obstacle(scene);
    obstacle->randomSpawn();

    Treasure *treasure = new Treasure(scene);
    treasure->randomSpawn();

    view->scale(2,2);
    setCentralWidget(view);
    setFixedSize(sizeHint());
}

Bombertronic::~Bombertronic()
{}



