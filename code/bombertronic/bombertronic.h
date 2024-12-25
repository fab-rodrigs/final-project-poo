#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_bombertronic.h"

class bombertronic : public QMainWindow
{
    Q_OBJECT

public:
    bombertronic(QWidget *parent = nullptr);
    ~bombertronic();
    void createMatrix();

private:
    Ui::bombertronicClass ui;
};
