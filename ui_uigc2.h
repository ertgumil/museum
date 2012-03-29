/********************************************************************************
** Form generated from reading UI file 'uigc2.ui'
**
** Created: Thu Mar 29 17:43:04 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIGC2_H
#define UI_UIGC2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "GLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_UIGC2
{
public:
    QAction *actionBlau;
    QAction *actionLoad;
    QAction *actionFullscreen;
    QAction *actionWindowed;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    GLWidget *contextGL;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuColor_Fons;
    QMenu *menuOpcions;
    QMenu *menuFile;
    QMenu *menuView;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;
    QToolBar *toolBar_5;
    QToolBar *toolBar_6;

    void setupUi(QMainWindow *UIGC2)
    {
        if (UIGC2->objectName().isEmpty())
            UIGC2->setObjectName(QString::fromUtf8("UIGC2"));
        UIGC2->resize(302, 309);
        UIGC2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        actionBlau = new QAction(UIGC2);
        actionBlau->setObjectName(QString::fromUtf8("actionBlau"));
        actionLoad = new QAction(UIGC2);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionFullscreen = new QAction(UIGC2);
        actionFullscreen->setObjectName(QString::fromUtf8("actionFullscreen"));
        actionWindowed = new QAction(UIGC2);
        actionWindowed->setObjectName(QString::fromUtf8("actionWindowed"));
        centralWidget = new QWidget(UIGC2);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        contextGL = new GLWidget(centralWidget);
        contextGL->setObjectName(QString::fromUtf8("contextGL"));

        horizontalLayout->addWidget(contextGL);

        UIGC2->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(UIGC2);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UIGC2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(UIGC2);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 302, 25));
        menuBar->setMinimumSize(QSize(10, 10));
        menuColor_Fons = new QMenu(menuBar);
        menuColor_Fons->setObjectName(QString::fromUtf8("menuColor_Fons"));
        menuOpcions = new QMenu(menuBar);
        menuOpcions->setObjectName(QString::fromUtf8("menuOpcions"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        UIGC2->setMenuBar(menuBar);
        statusBar = new QStatusBar(UIGC2);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UIGC2->setStatusBar(statusBar);
        toolBar = new QToolBar(UIGC2);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        UIGC2->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(UIGC2);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        UIGC2->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(UIGC2);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        UIGC2->addToolBar(Qt::TopToolBarArea, toolBar_3);
        toolBar_4 = new QToolBar(UIGC2);
        toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
        UIGC2->addToolBar(Qt::TopToolBarArea, toolBar_4);
        toolBar_5 = new QToolBar(UIGC2);
        toolBar_5->setObjectName(QString::fromUtf8("toolBar_5"));
        UIGC2->addToolBar(Qt::TopToolBarArea, toolBar_5);
        toolBar_6 = new QToolBar(UIGC2);
        toolBar_6->setObjectName(QString::fromUtf8("toolBar_6"));
        UIGC2->addToolBar(Qt::TopToolBarArea, toolBar_6);

        menuBar->addAction(menuColor_Fons->menuAction());
        menuBar->addAction(menuOpcions->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuColor_Fons->addAction(actionBlau);
        menuFile->addAction(actionLoad);
        menuView->addAction(actionFullscreen);
        menuView->addAction(actionWindowed);

        retranslateUi(UIGC2);
        QObject::connect(actionBlau, SIGNAL(triggered()), contextGL, SLOT(SetBackgroundBlue()));
        QObject::connect(actionLoad, SIGNAL(triggered()), contextGL, SLOT(LoadFiles()));
        QObject::connect(actionFullscreen, SIGNAL(triggered()), UIGC2, SLOT(showFullScreen()));
        QObject::connect(actionWindowed, SIGNAL(triggered()), UIGC2, SLOT(showMaximized()));

        QMetaObject::connectSlotsByName(UIGC2);
    } // setupUi

    void retranslateUi(QMainWindow *UIGC2)
    {
        UIGC2->setWindowTitle(QApplication::translate("UIGC2", "UIGC2", 0, QApplication::UnicodeUTF8));
        actionBlau->setText(QApplication::translate("UIGC2", "Blau", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("UIGC2", "Load", 0, QApplication::UnicodeUTF8));
        actionFullscreen->setText(QApplication::translate("UIGC2", "Fullscreen", 0, QApplication::UnicodeUTF8));
        actionWindowed->setText(QApplication::translate("UIGC2", "Windowed", 0, QApplication::UnicodeUTF8));
        menuColor_Fons->setStyleSheet(QApplication::translate("UIGC2", "background-color: rgb(255, 255, 255);\n"
"", 0, QApplication::UnicodeUTF8));
        menuColor_Fons->setTitle(QApplication::translate("UIGC2", "Color Fons", 0, QApplication::UnicodeUTF8));
        menuOpcions->setTitle(QApplication::translate("UIGC2", "Opcions", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("UIGC2", "File", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("UIGC2", "View", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("UIGC2", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("UIGC2", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("UIGC2", "toolBar_3", 0, QApplication::UnicodeUTF8));
        toolBar_4->setWindowTitle(QApplication::translate("UIGC2", "toolBar_4", 0, QApplication::UnicodeUTF8));
        toolBar_5->setWindowTitle(QApplication::translate("UIGC2", "toolBar_5", 0, QApplication::UnicodeUTF8));
        toolBar_6->setWindowTitle(QApplication::translate("UIGC2", "toolBar_6", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UIGC2: public Ui_UIGC2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIGC2_H
