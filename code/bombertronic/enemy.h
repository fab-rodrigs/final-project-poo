#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>

class Enemy : public QGraphicsPixmapItem{
private:
    int x, y;
    int position;
public:
    Enemy(int startX, int startY);
    void randomMoviment();
    void attackPlayer();
};

#endif // ENEMY_H
