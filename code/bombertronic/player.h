#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "map.h"

class PowerUp;

class Player : public QGraphicsPixmapItem{
private:
    int x,y;
    int lifeQuantity;
    int score;
    int bestScore;
    int powerUpType;
    Map * map;
    PowerUp *power;
public:
    Player(int startX, int startY, Map * map);
    void move(int newX, int newY);
    void loseLife();
    void addScore();
    void die(int powerType);
    void win();

    int getX();
    int getY();
};

class PowerUp : public QGraphicsPixmapItem{
private:
    int type;
public:
    PowerUp();
    int usePowerUp(int type);
};

#endif // PLAYER_H
