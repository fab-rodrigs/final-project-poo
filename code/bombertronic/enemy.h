#ifndef ENEMY_H
#define ENEMY_H

#endif // ENEMY_H

class Enemy {
private:
    int x, y;
    int position;
public:
    Enemy(int startX, int startY);
    void randomMoviment();
    void attackPlayer();
};
