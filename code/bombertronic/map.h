#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Map {
protected:
    int i, j;
    QGraphicsScene * scene;
public:
    Map(QGraphicsScene * scene, int i, int j);
    void generateMap();
    int getCell(int x, int y);
    void setCell(int x, int y, int value);
    bool checkPos(int x, int y);
};

class Obstacle : public Map{
private:
    bool breakable;
    int spawnPosition;
public:
    Obstacle(QGraphicsScene *scene);
    void randomSpawn();
};

class Treasure : public Map{
private:
    int spawnPosition;
    int item;
public:
    Treasure(QGraphicsScene *scene);
    void randomSpawn();
    void dropItem();
};

#endif // MAP_H
