#ifndef BOMBERTRONIC_H
#define BOMBERTRONIC_H

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "player.h"
#include "map.h"
#include "enemy.h"
#include "bomb.h"

class Bombertronic : public QMainWindow
{
    Q_OBJECT

public:
    Bombertronic(QWidget *parent = nullptr);
    ~Bombertronic();
    void keyPressEvent(QKeyEvent * event);

private:
    QGraphicsScene * scene;
    QGraphicsView  * view;
    Map * map;
    Player * player;
    Enemy * enemy1;
    Enemy * enemy2;
    Enemy * enemy3;
    Enemy * enemy4;
    Bomb * bomb;
};

#endif // BOMBERTRONIC_H
