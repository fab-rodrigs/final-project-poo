#ifndef BOMBERTRONIC_H
#define BOMBERTRONIC_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QPixmap>
#include <QString>

#include "player.h"
#include "map.h"
#include "enemy.h"
#include "bomb.h"

class bombertronic : public QMainWindow
{
    Q_OBJECT

public:
    bombertronic(QWidget *parent = nullptr);
    ~bombertronic();
    void createMatrix();
    void paintEvent(QPaintEvent* event);
    //void keyPressEvent(QKeyEvent* event);

private:
    int matriz[13][15];
    QWidget* centralWidget;
    QGridLayout* gridLayout;
};

#endif // BOMBERTRONIC_H


