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
    Treasure *_treasure;
    PowerUp *_power;
    int powerType = 0;
public:
    Bomb(Map *map, Player *player, Enemy *enemy, Treasure *treasure, PowerUp *power, int x, int y);
    void changeType();
    void tick();
    void explode();
    bool isExploded();
    void detector(int cellX, int cellY, Map *map, Player *player, Enemy *enemy, Treasure *treasure);
};


#endif // BOMB_H
