#include "player.h"
#include <QGraphicsScene>

Player::Player(int startX, int startY){
    x = startX;
    y = startY;

    setPixmap(QPixmap(":/img/player.png").scaledToWidth(16));  // Define sprite do jogador
    setPos(startX, startY);  // Define posição inicial
}

void Player::move(int newX, int newY) {
    if(newX){
        x = newX;
    }
    else{
        y = newY;
    }
}

