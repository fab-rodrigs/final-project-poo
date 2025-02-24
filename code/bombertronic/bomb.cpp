#include "bomb.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

Bomb::Bomb(Map *map, Player *player, Enemy *enemy, int x, int y) : _map(map), _x(x), _y(y), _player(player), _enemy(enemy){
    setPixmap(QPixmap(":/img/capacitor.png").scaledToWidth(16));
    setPos(x, y);

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &Bomb::explode);
    qDebug() << "3..2..1..";
    timer->start(3000);
}

void Bomb::explode() {
    qDebug() << "Coordenadas da bomba: (" << _x << ", " << _y << ")";

    setPixmap(QPixmap(":/img/fire-final-top.png").scaledToWidth(16));

    QTimer::singleShot(500, this, [this]() {
        scene()->removeItem(this);
        delete this;
        qDebug() << "A bomba explodiu!";
    });

    int cellX = _x / 16;
    int cellY = _y / 16;

    // Verifica à direita
    if (_map->getCell((cellX + 1) * 16, cellY * 16) == 4) {
        qDebug() << "Caixa encontrada à direita! Removendo...";
        _map->setCell((cellX + 1) * 16, cellY * 16);
    }

    // Verifica à esquerda
    if (_map->getCell((cellX - 1) * 16, cellY * 16) == 4) {
        qDebug() << "Caixa encontrada à esquerda! Removendo...";
        _map->setCell((cellX - 1) * 16, cellY * 16);
    }

    // Verifica acima
    if (_map->getCell(cellX * 16, (cellY - 1) * 16) == 4) {
        qDebug() << "Caixa encontrada acima! Removendo...";
        _map->setCell(cellX * 16, (cellY - 1) * 16);
    }

    // Verifica abaixo
    if (_map->getCell(cellX * 16, (cellY + 1) * 16) == 4) {
        qDebug() << "Caixa encontrada abaixo! Removendo...";
        _map->setCell(cellX * 16, (cellY + 1) * 16);
    }

    if ((_player->getX() == _x && _player->getY() == _y) || // Célula da bomba
      (_player->getX() == _x + 16 && _player->getY() == _y) || // Direita
      (_player->getX() == _x - 16 && _player->getY() == _y) || // Esquerda
      (_player->getX() == _x && _player->getY() == _y + 16) || // Abaixo
      (_player->getX() == _x && _player->getY() == _y - 16)) { // Acima
        qDebug() << "Jogador atingido pela explosão!";
        _player->die();
    }

    if ((_enemy->getX() == _x && _enemy->getY() == _y) || // Célula da bomba
        (_enemy->getX() == _x + 16 && _enemy->getY() == _y) || // Direita
        (_enemy->getX() == _x - 16 && _enemy->getY() == _y) || // Esquerda
        (_enemy->getX() == _x && _enemy->getY() == _y + 16) || // Abaixo
        (_enemy->getX() == _x && _enemy->getY() == _y - 16)) { // Acima
        qDebug() << "Inimigo atingido pela explosão!";
        _enemy->die();
    }
}
