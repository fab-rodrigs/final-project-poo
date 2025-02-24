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

    map = new Map(scene, 240, 240);
    map->generateMap();

    player = new Player(16, 48, map);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    enemy1 = new Enemy(112, 48, map, player);
    scene->addItem(enemy1);

    //enemy4 = new Enemy(112, 208, map);
    //scene->addItem(enemy4);

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
    if(event->key() == Qt::Key_D){
        player->move(player->getX()+16, player->getY());
    }
    if(event->key() == Qt::Key_W){
        player->move(player->getX(), player->getY()-16);
    }
    if(event->key() == Qt::Key_S){
        player->move(player->getX(), player->getY()+16);
    }
    if(event->key() == Qt::Key_Space){
        bomb = new Bomb(map, player, enemy1, player->getX(), player->getY());
        scene->addItem(bomb);
        qDebug() << "A bomba foi plantada!";
    }
    player->setPos(player->getX(), player->getY());
}





