#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
//#include "player.h"

class Map {
protected:
    int i, j;
    QGraphicsScene * scene;
    QString mapData[240][240];
public:
    Map(QGraphicsScene * scene, int i, int j);
    void generateMap();
    int getCell(int x, int y);
    void setCell(int x, int y);
    bool checkPos(int x, int y);
};

class Obstacle : public Map{
private:
    bool breakable;
    int spawnPosition;
public:
    Obstacle(QGraphicsScene *scene);
};

class Treasure : public Map, public QGraphicsPixmapItem{
private:
    int spawnPosition;
    int item;
public:
    Treasure(QGraphicsScene *scene);
    void getPower(int x, int y);
};

#endif // MAP_H
