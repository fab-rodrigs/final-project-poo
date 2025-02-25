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
    Player *_player;
    PowerUp *_power;
    int powerType = 0;
    QTimer * timer;

public:
    Enemy(int startX, int startY, Map *map, Player *player, PowerUp *power);
    void randomMoviment();
    void die();
    void kill();

    int getX();
    int getY();

    virtual ~Enemy();
};

#endif // ENEMY_H
