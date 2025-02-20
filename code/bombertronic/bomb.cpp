#include "bomb.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

Bomb::Bomb(int x, int y) {
    setPixmap(QPixmap(":/img/capacitor.png").scaledToWidth(16));
    setPos(x, y);

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true); // para o inimigo, não usar single shot, sortear uma direção para ele se movimentar
    connect(timer, &QTimer::timeout, this, &Bomb::explode);
    qDebug() << "3..2..1..";
    timer->start(3000);
}

void Bomb::explode() {
    qDebug() << "A bomba explodiu!";

    setPixmap(QPixmap(":/img/fire-final-top.png").scaledToWidth(16));

    QTimer::singleShot(500, this, [this]() {
        scene()->removeItem(this);
        delete this;
    });
}

