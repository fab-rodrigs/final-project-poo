#include "bomb.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

Bomb::Bomb(Map *map, Player *player, Enemy *enemy, Treasure *treasure, PowerUp *power, int x, int y) : _map(map), _x(x), _y(y), _player(player), _enemy(enemy), _treasure(treasure), _power(power){
    setPixmap(QPixmap(":/img/capacitor.png").scaledToWidth(16));
    setPos(x, y);

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &Bomb::explode);
    qDebug() << "3..2..1..";
    timer->start(2000);
}

void Bomb::explode() {
    qDebug() << "Coordenadas da bomba: (" << _x << ", " << _y << ")";

    setPixmap(QPixmap(":/img/fire-final-top.png").scaledToWidth(16));

    int cellX = _x / 16;
    int cellY = _y / 16;

    detector(cellX, cellY, _map, _player, _enemy, _treasure);

    QTimer::singleShot(500, this, [this]() {
        scene()->removeItem(this);
        delete this;
        qDebug() << "A bomba explodiu!";
    });




}

void Bomb::detector(int cellX, int cellY, Map *_map, Player *_player, Enemy *_enemy, Treasure *_treasure){

    if (_map->getCell((cellX + 1) * 16, cellY * 16) == 4) { // Direita
        qDebug() << "Caixa encontrada à direita! Removendo...";
        _map->setCell((cellX + 1) * 16, cellY * 16);
    }
    else if (_map->getCell((cellX + 1) * 16, cellY * 16) == 3) { // Direita
        qDebug() << "Tesouro encontrado à direita! Obtendo power-up...";
        powerType = _power->usePowerUp(1);
        qDebug() << "PowerType = " << powerType;
        _map->setCell((cellX - 1) * 16, cellY * 16);
    }

    if (_map->getCell((cellX - 1) * 16, cellY * 16) == 4) { // Esquerda
        qDebug() << "Caixa encontrada à esquerda! Removendo...";
        _map->setCell((cellX - 1) * 16, cellY * 16);
    }
    else if (_map->getCell((cellX - 1) * 16, cellY * 16) == 3) { // Esquerda
        qDebug() << "Tesouro encontrado à direita! Obtendo power-up...";
        _player->setPowerType(_power->usePowerUp(1));
        qDebug() << "PowerType = " << powerType;
        _map->setCell((cellX - 1) * 16, cellY * 16);
    }

    if (_map->getCell(cellX * 16, (cellY - 1) * 16) == 4) { // Acima
        qDebug() << "Caixa encontrada acima! Removendo...";
        _map->setCell(cellX * 16, (cellY - 1) * 16);
    }
    else if (_map->getCell(cellX * 16, (cellY - 1) * 16) == 3) { // Acima
        qDebug() << "Tesouro encontrado à direita! Obtendo power-up...";
        powerType = _power->usePowerUp(1);
        qDebug() << "PowerType = " << powerType;
        _map->setCell(cellX * 16, (cellY - 1) * 16);
    }

    if (_map->getCell(cellX * 16, (cellY + 1) * 16) == 4) { // Abaixo
        qDebug() << "Caixa encontrada abaixo! Removendo...";
        _map->setCell(cellX * 16, (cellY + 1) * 16);
    }

    else if (_map->getCell(cellX * 16, (cellY + 1) * 16) == 3) { // Abaixo
        qDebug() << "Tesouro encontrado à direita! Obtendo power-up...";
        powerType = _power->usePowerUp(1);
        qDebug() << "PowerType = " << powerType;
        _map->setCell(cellX * 16, (cellY + 1) * 16);
    }

    if ((_player->getX() == _x && _player->getY() == _y) || // Célula da bomba
        (_player->getX() == _x + 16 && _player->getY() == _y) || // Direita
        (_player->getX() == _x - 16 && _player->getY() == _y) || // Esquerda
        (_player->getX() == _x && _player->getY() == _y + 16) || // Abaixo
        (_player->getX() == _x && _player->getY() == _y - 16)) { // Acima
        qDebug() << "Jogador atingido pela explosão!";
        qDebug() << "PowerType = " << powerType;
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
