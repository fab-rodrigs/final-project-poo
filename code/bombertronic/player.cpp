#include "player.h"
#include <QGraphicsScene>

Player::Player(int startX, int startY){
    x = startX;
    y = startY;

    setPixmap(QPixmap(":/img/player.png").scaledToWidth(16));
    setPos(startX, startY);
}

void Player::move(int newX, int newY) {
    if(newX){
        x = newX;
    }
    else{
        y = newY;
    }
}

