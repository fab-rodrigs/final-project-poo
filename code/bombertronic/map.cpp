#include "map.h"
#include <cstdlib>
#include <ctime>
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
            }
            else if (i==16){ // black
                image = ":/img/black.png";
            }
            else if (i==208 & j==208){ // portal
                image = ":/img/portal.png";
            }
            else{
                image = ":/img/ground.png";
            }
            QGraphicsPixmapItem * wall = scene->addPixmap(QPixmap(image).scaledToWidth(16));
            wall->setPos(j,i);
        }
    }
}

int Map::getCell(int x, int y){

}

void Map::setCell(int x, int y, int value){

}

Obstacle::Obstacle(){

}

void Obstacle::randomSpawn(){

}

Treasure::Treasure(){

}

void Treasure::randomSpawn(){

}

void Treasure::dropItem(){

}
