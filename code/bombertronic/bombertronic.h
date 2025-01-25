#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QPixmap>
#include <QString>

class Player {
public:
    int x, y;
    QPixmap sprite;

    Player(int startX, int startY) {
        x = startX;
        y = startY;
        sprite = QPixmap(":/img/player.png");
    }
};

class Bot {
public:
    int x, y;
    QPixmap sprite;

    Bot(int startX, int startY){
        x = startX;
        y = startY;
        sprite = QPixmap(":/img/bot.png");
    }
};

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
    Player* player;
    Bot* bot;
};


