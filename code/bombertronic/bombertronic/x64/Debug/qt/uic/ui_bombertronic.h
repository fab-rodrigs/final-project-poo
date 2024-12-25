/********************************************************************************
** Form generated from reading UI file 'bombertronic.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOMBERTRONIC_H
#define UI_BOMBERTRONIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bombertronicClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *bombertronicClass)
    {
        if (bombertronicClass->objectName().isEmpty())
            bombertronicClass->setObjectName("bombertronicClass");
        bombertronicClass->resize(600, 400);
        menuBar = new QMenuBar(bombertronicClass);
        menuBar->setObjectName("menuBar");
        bombertronicClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(bombertronicClass);
        mainToolBar->setObjectName("mainToolBar");
        bombertronicClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(bombertronicClass);
        centralWidget->setObjectName("centralWidget");
        bombertronicClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(bombertronicClass);
        statusBar->setObjectName("statusBar");
        bombertronicClass->setStatusBar(statusBar);

        retranslateUi(bombertronicClass);

        QMetaObject::connectSlotsByName(bombertronicClass);
    } // setupUi

    void retranslateUi(QMainWindow *bombertronicClass)
    {
        bombertronicClass->setWindowTitle(QCoreApplication::translate("bombertronicClass", "bombertronic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bombertronicClass: public Ui_bombertronicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOMBERTRONIC_H
