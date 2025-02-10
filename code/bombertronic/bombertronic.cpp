#include "bombertronic.h"
#include <cstdlib>
#include <ctime>

#include <QGraphicsPixmapItem>
#include <QString>
#include <QKeyEvent>
#include <QDebug>

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

    player = new Player(16, 48);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    view->scale(2.3,2.3);
    setCentralWidget(view);
    setFixedSize(sizeHint());
}

Bombertronic::~Bombertronic()
{}

void Bombertronic::keyPressEvent(QKeyEvent * event)
{
    qDebug() << "Tecla pressionada:" << event->key();

    if(event->key() == Qt::Key_A){
        player->move(player->getX()-16, 0);
    }
    else if(event->key() == Qt::Key_D){
        player->move(player->getX()+16, 0);
    }
    else if(event->key() == Qt::Key_W){
        player->move(0, player->getY()-16);
    }
    else if(event->key() == Qt::Key_S){
        player->move(0, player->getY()+16);
    }

    player->setPos(player->getX(), player->getY()); // Atualiza posição no jogo
}





