#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include "player.h"
#include "map.h"

class Enemy : public QGraphicsPixmapItem, public QObject{
private:
    int x, y;
    int position;
    int direction;
    Map *map;
    Player *player;
public:
    Enemy(int startX, int startY, Map *map, Player *player);
    void randomMoviment();
    void die();
    void kill();

    int getX();
    int getY();
};

#endif // ENEMY_H
