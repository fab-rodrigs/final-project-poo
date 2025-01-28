#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int x,y;
    int lifeQuantity;
    int score;
    int bestScore;
    int powerUpType;
public:
    Player(int startX, int startY);
    void move();
    void loseLife();
    void addScore();
    void usePowerUp();
    int getX();
    int getY();
};

class PowerUp {
private:
    int type;
public:
    PowerUp();
    void usePower();
};

#endif // PLAYER_H
