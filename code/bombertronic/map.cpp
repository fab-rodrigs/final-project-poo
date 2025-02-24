#include "map.h"
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include "player.h"
using namespace std;

Map::Map(QGraphicsScene * scene, int i, int j){
    this->scene = scene;
    this->i = i;
    this->j = j;
    scene->setSceneRect(0,0,i,j);
}

void Map::generateMap(){
    srand(time(0));

    for (int i = 0; i <= 240; i=i+16) {
        for (int j = 0; j <= 240; j=j+16) {
            QString image = "";
            if (i==0 || j==0 || i==224 || j==224 || i==32 || (i%32==0) & (j%32==0)){ // wall
                image = ":/img/wall.png";
                mapData[i / 16][j / 16] = "wall";
            }
            else if((i==48 && j==16) || (i==48 && j==32) || (i==64 && j==16) || (i==128 && j==16) || (i==128 && j==208)
                     || (i==48 && j==112) || (i==208 && j==112) || (i==208 && j==192) || (i==192 && j==208)){
                image = ":/img/ground.png";
                mapData[i / 16][j / 16] = "ground";
            }
            else if (i==16){ // black
                image = ":/img/black.png";
                mapData[i / 16][j / 16] = "black";
            }
            else if (i==208 & j==208){ // portal
                image = ":/img/portal.png";
                mapData[i / 16][j / 16] = "portal";
            }
            else if((i==48 && j==208) || (i==128 && j==112) || (i==208 && j==16)){
                if (rand() % 100 <= 80) {
                    image = ":/img/lucky.png";
                    mapData[i / 16][j / 16] = "lucky";
                }
                else{
                    image = ":/img/box.png";
                    mapData[i / 16][j / 16] = "box";
                }
            }
            else{
                if (rand() % 2) {
                    image = ":/img/ground.png";
                    mapData[i / 16][j / 16] = "ground";
                }
                else{
                    image = ":/img/box.png";
                    mapData[i / 16][j / 16] = "box";
                }
            }
            QGraphicsPixmapItem * wall = scene->addPixmap(QPixmap(image).scaledToWidth(16));
            wall->setPos(j,i);
        }
    }
}




Obstacle::Obstacle(QGraphicsScene *scene) : Map(scene, 240, 240) {}


Treasure::Treasure(QGraphicsScene *scene) : Map(scene, 240, 240) {

}


void Treasure::dropItem(){

}

int Map::getCell(int x, int y) {
    int cellX = x / 16;
    int cellY = y / 16;

    QString cellType = mapData[cellY][cellX];
    qDebug() << "Célula: (" << x << ", " << y << ") -> Tipo: " << cellType;

    if (cellType == "wall") {
        return 1;
    } else if (cellType == "portal") {
        return 2;
    } else if (cellType == "lucky") {
        return 3;
    } else if (cellType == "box") {
        return 4;
    }


    return 0;
}

bool Map::checkPos(int x, int y) {
    int cell = getCell(x, y);

    switch(cell){
    case -1: // fora do mapa
        return false;
        break;
    case 0: // ground
        return true;
        break;
    case 1: // wall
        return false;
        break;
    case 2: // portal
        Player * player;
        player->win();
        return true;
        break;
    case 3: // treasure
        return true;
        break;
    case 4: // box
        return false;
        break;
    default: // valid
        return true;
        break;
    }
}

void Map::setCell(int x, int y) {
    int cellX = x / 16;
    int cellY = y / 16;

    mapData[cellY][cellX] = "ground";

    // Remove o item antigo da célula
    QList<QGraphicsItem*> items = scene->items(QPointF(x, y), Qt::IntersectsItemShape, Qt::DescendingOrder);
    for (QGraphicsItem* item : items) {
        if (item->type() == QGraphicsPixmapItem::Type) {
            scene->removeItem(item);
            delete item;
        }
    }

    // Adiciona o novo item na célula
    QGraphicsPixmapItem * newItem = scene->addPixmap(QPixmap(":/img/ground.png").scaledToWidth(16));
    newItem->setPos(x, y);
    newItem->setZValue(0);


    qDebug() << "Célula (" << x << ", " << y << ") atualizada para: ground";
}
