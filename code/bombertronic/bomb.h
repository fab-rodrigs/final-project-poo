#ifndef BOMB_H
#define BOMB_H

class Bomb {
private:
    int x,y;
    int type;
    int explosionDistance;
    int explosionDirection;
    int timer;
    bool exploded;
public:
    Bomb(int x, int y, int timer, int explosionDistance, int explosionDirection, int type);
    void changeType();
    void tick();
    void explode();
    bool isExploded();
};


#endif // BOMB_H
