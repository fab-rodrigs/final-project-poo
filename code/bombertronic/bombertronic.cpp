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

    //Obstacle *obstacle = new Obstacle(scene);
    //obstacle->randomSpawn();

    //Treasure *treasure = new Treasure(scene);
    //treasure->randomSpawn();

    map = new Map(scene, 240, 240);
    map->generateMap();

    enemy1 = new Enemy(112, 48);
    scene->addItem(enemy1);

    enemy2 = new Enemy(16, 128);
    scene->addItem(enemy2);

    enemy3 = new Enemy(208, 128);
    scene->addItem(enemy3);

    enemy4 = new Enemy(112, 208);
    scene->addItem(enemy4);

    player = new Player(16, 48, map);
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
    //qDebug() << "Tecla pressionada:" << event->key();

    if(event->key() == Qt::Key_A){
        player->move(player->getX()-16, player->getY());
    }
    else if(event->key() == Qt::Key_D){
        player->move(player->getX()+16, player->getY());
    }
    else if(event->key() == Qt::Key_W){
        player->move(player->getX(), player->getY()-16);
    }
    else if(event->key() == Qt::Key_S){
        player->move(player->getX(), player->getY()+16);
    }

    player->setPos(player->getX(), player->getY());
}





