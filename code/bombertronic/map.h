#ifndef MAP_H
#define MAP_H

class Map {
private:
    int rows, cols;
public:
    Map(int rows, int cols);
    void generateMap();
    int getCell(int x, int y);
    void setCell(int x, int y, int value);
};

class Obstacle {
private:
    bool breakable;
    int spawnPosition;
public:
    Obstacle();
    void randomSpawn();
};

class Treasure {
private:
    int spawnPosition;
    int item;
public:
    Treasure();
    void randomSpawn();
    void dropItem();
};

#endif // MAP_H
