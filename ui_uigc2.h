/********************************************************************************
** Form generated from reading UI file 'uigc2.ui'
**
** Created: Thu Mar 8 12:59:11 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIGC2_H
#define UI_UIGC2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
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
    QAction *action4_vistas;
    QAction *actionProjeccio;
    QAction *actionOrtogonal;
    QAction *action1_vista;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    GLWidget *contextGL;
    QMenuBar *menuBar;
    QMenu *menuColor_fons;
    QMenu *menuVisualitzacio;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UIGC2)
    {
        if (UIGC2->objectName().isEmpty())
            UIGC2->setObjectName(QString::fromUtf8("UIGC2"));
        UIGC2->resize(600, 500);
        actionBlau = new QAction(UIGC2);
        actionBlau->setObjectName(QString::fromUtf8("actionBlau"));
        actionBlau->setCheckable(false);
        action4_vistas = new QAction(UIGC2);
        action4_vistas->setObjectName(QString::fromUtf8("action4_vistas"));
        actionProjeccio = new QAction(UIGC2);
        actionProjeccio->setObjectName(QString::fromUtf8("actionProjeccio"));
        actionOrtogonal = new QAction(UIGC2);
        actionOrtogonal->setObjectName(QString::fromUtf8("actionOrtogonal"));
        action1_vista = new QAction(UIGC2);
        action1_vista->setObjectName(QString::fromUtf8("action1_vista"));
        centralWidget = new QWidget(UIGC2);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(200, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        contextGL = new GLWidget(centralWidget);
        contextGL->setObjectName(QString::fromUtf8("contextGL"));

        horizontalLayout->addWidget(contextGL);

        UIGC2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UIGC2);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        menuBar->setMinimumSize(QSize(0, 0));
        menuBar->setBaseSize(QSize(0, 0));
        menuColor_fons = new QMenu(menuBar);
        menuColor_fons->setObjectName(QString::fromUtf8("menuColor_fons"));
        menuVisualitzacio = new QMenu(menuBar);
        menuVisualitzacio->setObjectName(QString::fromUtf8("menuVisualitzacio"));
        UIGC2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UIGC2);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UIGC2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UIGC2);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UIGC2->setStatusBar(statusBar);

        menuBar->addAction(menuColor_fons->menuAction());
        menuBar->addAction(menuVisualitzacio->menuAction());
        menuColor_fons->addAction(actionBlau);
        menuVisualitzacio->addAction(action4_vistas);
        menuVisualitzacio->addAction(actionProjeccio);
        menuVisualitzacio->addAction(actionOrtogonal);
        menuVisualitzacio->addAction(action1_vista);

        retranslateUi(UIGC2);
        QObject::connect(actionBlau, SIGNAL(triggered()), contextGL, SLOT(SetBackgroundBlue()));
        QObject::connect(action4_vistas, SIGNAL(triggered()), contextGL, SLOT(SeveralViews()));
        QObject::connect(actionOrtogonal, SIGNAL(triggered()), contextGL, SLOT(OrthoView()));
        QObject::connect(actionProjeccio, SIGNAL(triggered()), contextGL, SLOT(ProjView()));
        QObject::connect(action1_vista, SIGNAL(triggered()), contextGL, SLOT(FullView()));

        QMetaObject::connectSlotsByName(UIGC2);
    } // setupUi

    void retranslateUi(QMainWindow *UIGC2)
    {
        UIGC2->setWindowTitle(QApplication::translate("UIGC2", "UIGC2", 0, QApplication::UnicodeUTF8));
        actionBlau->setText(QApplication::translate("UIGC2", "Blau", 0, QApplication::UnicodeUTF8));
        action4_vistas->setText(QApplication::translate("UIGC2", "4 vistas", 0, QApplication::UnicodeUTF8));
        actionProjeccio->setText(QApplication::translate("UIGC2", "Projeccio", 0, QApplication::UnicodeUTF8));
        actionOrtogonal->setText(QApplication::translate("UIGC2", "Ortogonal", 0, QApplication::UnicodeUTF8));
        action1_vista->setText(QApplication::translate("UIGC2", "1 vista", 0, QApplication::UnicodeUTF8));
        menuColor_fons->setTitle(QApplication::translate("UIGC2", "Color fons", 0, QApplication::UnicodeUTF8));
        menuVisualitzacio->setTitle(QApplication::translate("UIGC2", "Visualitzacio", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UIGC2: public Ui_UIGC2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIGC2_H
