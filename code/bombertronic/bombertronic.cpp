#include "bombertronic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <QPixmap>
#include <QString>
#include <QLabel>
#include <QGridLayout>
#include <QPainter>

using namespace std;

bombertronic::bombertronic(QWidget* parent)
    : QMainWindow(parent), centralWidget(new QWidget(this)), gridLayout(new QGridLayout)
{
    setCentralWidget(centralWidget);
    centralWidget->setLayout(gridLayout);
    createMatrix();
}

bombertronic::~bombertronic()
{}

void bombertronic::createMatrix()
{
    srand(time(0));

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 15; j++) {
            if (i == 0 || j == 0 || i == 12 || j == 14 || (i % 2 == 0 && j % 2 == 0)) {
                matriz[i][j] = 1;
            }
            else if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) ||
                (i == 11 && j == 12) || (i == 11 && j == 13) || (i == 10 && j == 13)) {
                matriz[i][j] = 0;
            }
            else if ((i == 11 && j == 1) || (i == 6 && j == 7) || (i == 1 && j == 13)) {
                matriz[i][j] = (rand() % 10 < 6) ? 3 : 0;
            }
            else {
                matriz[i][j] = (rand() % 2 == 0) ? 2 : 0;
            }
        }
    }

    update();  // Atualiza a tela para chamar paintEvent
}

void bombertronic::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    const int cellSize = 50;
    const int numRows = 13;
    const int numCols = 15;

    resize(numCols * cellSize, numRows * cellSize);

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 15; j++) {
            QPixmap imagem;

            switch (matriz[i][j]) {
            case 0:
                imagem.load(":/img/0.png");
                break;
            case 1:
                imagem.load(":/img/1.png");
                break;
            case 2:
                imagem.load(":/img/2.png");
                break;
            case 3:
                imagem.load(":/img/3.png");
                break;
            default:
                imagem.load(":/img/0.png");
                break;
            }

            // Desenha a imagem na posição (i, j)
            painter.drawPixmap(j * cellSize, i * cellSize, cellSize, cellSize, imagem);
        }
    }
}
