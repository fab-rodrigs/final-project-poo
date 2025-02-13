#include "player.h"
#include <QGraphicsScene>
#include <qDebug>

Player::Player(int startX, int startY, Map * m){
    map = m;
    x = startX;
    y = startY;

    setPixmap(QPixmap(":/img/player.png").scaledToWidth(16));
    setPos(startX, startY);
}

void Player::move(int newX, int newY) {

    if(map->checkPos(newX, newY)){
        x = newX;
        y = newY;
    }
}

int Player::getX()
{
    qDebug() << "x = " << x;
    return x;
}

int Player::getY()
{
    qDebug() << "y = " << y;
    return y;
}

