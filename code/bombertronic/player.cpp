#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QMessageBox>
#include <qDebug>

Player::Player(int startX, int startY, Map * m){
    map = m;
    x = startX;
    y = startY;
    setZValue(1);

    setPixmap(QPixmap(":/img/player.png").scaledToWidth(16));
    setPos(startX, startY);
}

void Player::move(int newX, int newY) {

    if(map->checkPos(newX, newY)){
        x = newX;
        y = newY;
    }
}



void Player::win()
{
    QMessageBox gameWinBox;
    gameWinBox.setWindowTitle("Game Win");
    gameWinBox.setText("Você venceu!");
    gameWinBox.addButton("Sair", QMessageBox::RejectRole);
    gameWinBox.exec();

    if (gameWinBox.clickedButton()) {
        qDebug() << "Sair do jogo...";
        QApplication::quit(); // Fecha o aplicativo
    }
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}


int PowerUp::usePowerUp(int type)
{
    return type;
}

void Player::die(int powerType)
{
    QMessageBox gameOverBox;
    if(powerType){
        gameOverBox.setWindowTitle("Power-Up");
        gameOverBox.setText("Você possui mais uma vida!");
        gameOverBox.addButton("Continuar", QMessageBox::RejectRole);
        qDebug() << "PowerUp usado! O jogador possui uma vida extra.";
    }
    else{
        scene()->removeItem(this);
        gameOverBox.setWindowTitle("Game Over");
        gameOverBox.setText("Você morreu!");
        gameOverBox.addButton("Sair", QMessageBox::RejectRole);
        gameOverBox.exec();
        if (gameOverBox.clickedButton()) {
            qDebug() << "Sair do jogo...";
            QApplication::quit();
        }
        delete this;
    }
}
