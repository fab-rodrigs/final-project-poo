#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QPixmap>
#include <QString>

class bombertronic : public QMainWindow
{
    Q_OBJECT

public:
    bombertronic(QWidget *parent = nullptr);
    ~bombertronic();
    void createMatrix();
    void paintEvent(QPaintEvent* event);

private:
    int matriz[13][15];
    QWidget* centralWidget;
    QGridLayout* gridLayout;
};
