#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Map {
private:
    int i, j;
    QGraphicsScene * scene;
public:
    Map(QGraphicsScene * scene, int i, int j);
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
