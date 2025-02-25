#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

Enemy::Enemy(int startX, int startY, Map *map, Player *player, PowerUp *power) : map(map), _player(player), _power(power)
{
    srand(time(0));
    x = startX;
    y = startY;
    setZValue(1);
    direction = 1;

    setPixmap(QPixmap(":/img/bot.png").scaledToWidth(16));
    setPos(startX, startY);

    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &Enemy::randomMoviment);
    timer->start();
}

void Enemy::randomMoviment()
{
    int speed = 16;
    int nextX;
    int nextY;

    //qDebug() << "Inimigo se preparando...";

    if (rand() % 100 <= 50){
        nextX = x + speed * direction;
        nextY = y;
        if (map->checkPos(nextX, nextY)) {
            x = nextX;
        }
        else{
            direction *= -1;
            nextX = x + speed * direction;
            if (map->checkPos(nextX, nextY)) {
                x = nextX;
            }
        }
    }
    else{
        nextX = x;
        nextY = y + speed * direction;
        if (map->checkPos(nextX, nextY)) {
            y = nextY;
        }
        else{
            direction *= -1;
            nextY = y + speed * direction;
            if (map->checkPos(nextX, nextY)) {
                y = nextY;
            }
        }
    }
    setPos(x, y);
    //qDebug() << "Posição inimigo: (" << x << ", " << y << ")";
    //qDebug() << "Posição jogador: (" << _player->getX() << ", " << _player->getY() << ")"; //CRASHA AQUI

    if (_player && x == _player->getX() && y == _player->getY()) {
        qDebug() << "Inimigo matou o jogador!";
        _player->die();
    }
}

void Enemy::die()
{
    scene()->removeItem(this);
    delete this;
}


int Enemy::getX()
{
    return x;
}

int Enemy::getY()
{
    return y;
}

Enemy::~Enemy()
{
    delete timer;
}
