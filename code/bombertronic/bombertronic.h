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

private:
    QGraphicsScene * scene;
    QGraphicsView  * view;
};

#endif // BOMBERTRONIC_H
