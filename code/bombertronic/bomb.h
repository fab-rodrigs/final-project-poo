#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsPixmapItem>
#include "map.h"
#include "player.h"
#include "enemy.h"

class Bomb : public QGraphicsPixmapItem, public QObject{
private:
    int _x,_y;
    int type;
    int explosionDistance;
    int explosionDirection;
    int timer;
    bool exploded;
    Map *_map;
    Player *_player;
    Enemy *_enemy;
public:
    Bomb(Map *map, Player *player, int x, int y);
    void changeType();
    void tick();
    void explode();
    bool isExploded();
};


#endif // BOMB_H
