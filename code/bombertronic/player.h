#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <map.h>

class Player : public QGraphicsPixmapItem{
private:
    int x,y;
    int lifeQuantity;
    int score;
    int bestScore;
    int powerUpType;
    Map * map;

public:
    Player(int startX, int startY, Map * map);
    void move(int newX, int newY);
    void loseLife();
    void addScore();
    void usePowerUp();

    int getX() const { return x; }
    int getY() const { return y; }
};

class PowerUp {
private:
    int type;
public:
    PowerUp();
    void usePower();
};

#endif // PLAYER_H
