/********************************************************************************
** Form generated from reading UI file 'uigc2.ui'
**
** Created: Mon Mar 19 10:59:32 2012
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
    QAction *actionVista_perspectiva;
    QAction *actionVista_Ortogonal;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    GLWidget *contextGL;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuColor_Fons;
    QMenu *menuOpcions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UIGC2)
    {
        if (UIGC2->objectName().isEmpty())
            UIGC2->setObjectName(QString::fromUtf8("UIGC2"));
        UIGC2->resize(302, 309);
        UIGC2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        actionBlau = new QAction(UIGC2);
        actionBlau->setObjectName(QString::fromUtf8("actionBlau"));
        actionVista_perspectiva = new QAction(UIGC2);
        actionVista_perspectiva->setObjectName(QString::fromUtf8("actionVista_perspectiva"));
        actionVista_Ortogonal = new QAction(UIGC2);
        actionVista_Ortogonal->setObjectName(QString::fromUtf8("actionVista_Ortogonal"));
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
        menuBar->setGeometry(QRect(0, 0, 302, 23));
        menuBar->setMinimumSize(QSize(10, 10));
        menuColor_Fons = new QMenu(menuBar);
        menuColor_Fons->setObjectName(QString::fromUtf8("menuColor_Fons"));
        menuOpcions = new QMenu(menuBar);
        menuOpcions->setObjectName(QString::fromUtf8("menuOpcions"));
        UIGC2->setMenuBar(menuBar);
        statusBar = new QStatusBar(UIGC2);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UIGC2->setStatusBar(statusBar);

        menuBar->addAction(menuColor_Fons->menuAction());
        menuBar->addAction(menuOpcions->menuAction());
        menuColor_Fons->addAction(actionBlau);
        menuOpcions->addAction(actionVista_perspectiva);
        menuOpcions->addAction(actionVista_Ortogonal);

        retranslateUi(UIGC2);
        QObject::connect(actionBlau, SIGNAL(triggered()), contextGL, SLOT(SetBackgroundBlue()));
        QObject::connect(actionVista_Ortogonal, SIGNAL(triggered()), contextGL, SLOT(SetVistaOrtogonal()));
        QObject::connect(actionVista_perspectiva, SIGNAL(triggered()), contextGL, SLOT(SetVistaProjeccio()));

        QMetaObject::connectSlotsByName(UIGC2);
    } // setupUi

    void retranslateUi(QMainWindow *UIGC2)
    {
        UIGC2->setWindowTitle(QApplication::translate("UIGC2", "UIGC2", 0, QApplication::UnicodeUTF8));
        actionBlau->setText(QApplication::translate("UIGC2", "Blau", 0, QApplication::UnicodeUTF8));
        actionVista_perspectiva->setText(QApplication::translate("UIGC2", "Vista Perspectiva", 0, QApplication::UnicodeUTF8));
        actionVista_Ortogonal->setText(QApplication::translate("UIGC2", "Vista Ortogonal", 0, QApplication::UnicodeUTF8));
        menuColor_Fons->setStyleSheet(QApplication::translate("UIGC2", "background-color: rgb(255, 255, 255);\n"
"", 0, QApplication::UnicodeUTF8));
        menuColor_Fons->setTitle(QApplication::translate("UIGC2", "Color Fons", 0, QApplication::UnicodeUTF8));
        menuOpcions->setTitle(QApplication::translate("UIGC2", "Opcions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UIGC2: public Ui_UIGC2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIGC2_H
