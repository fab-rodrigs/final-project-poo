#include "enemy.h"
#include <QGraphicsScene>

Enemy::Enemy(int startX, int startY)
{
    x = startX;
    y = startY;

    setPixmap(QPixmap(":/img/bot.png").scaledToWidth(16));
    setPos(startX, startY);
}
