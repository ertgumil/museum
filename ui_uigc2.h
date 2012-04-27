/********************************************************************************
** Form generated from reading UI file 'uigc2.ui'
**
** Created: Fri Apr 27 15:44:51 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIGC2_H
#define UI_UIGC2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "GLWidget.h"
#include "glwidgetmap.h"

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
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSlider *potenciaSlider;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *lightList;
    QPushButton *addLight;
    QPushButton *deleteLight;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *rLight;
    QDoubleSpinBox *gLight;
    QLabel *label_5;
    QPushButton *paintLight;
    QDoubleSpinBox *aLight;
    QDoubleSpinBox *bLight;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *xPos;
    QDoubleSpinBox *yPos;
    QDoubleSpinBox *zPos;
    QLabel *label_4;
    QPushButton *moveLight;
    GLWidget *contextGL;
    glwidgetmap *widget;
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
        UIGC2->resize(892, 578);
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
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(250, 0));
        tabWidget->setMaximumSize(QSize(250, 16777215));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 230, 251, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        potenciaSlider = new QSlider(horizontalLayoutWidget);
        potenciaSlider->setObjectName(QString::fromUtf8("potenciaSlider"));
        potenciaSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(potenciaSlider);

        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 241, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lightList = new QComboBox(layoutWidget);
        lightList->setObjectName(QString::fromUtf8("lightList"));

        gridLayout->addWidget(lightList, 1, 0, 1, 1);

        addLight = new QPushButton(layoutWidget);
        addLight->setObjectName(QString::fromUtf8("addLight"));

        gridLayout->addWidget(addLight, 0, 2, 1, 1);

        deleteLight = new QPushButton(layoutWidget);
        deleteLight->setObjectName(QString::fromUtf8("deleteLight"));

        gridLayout->addWidget(deleteLight, 2, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 140, 251, 95));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        rLight = new QDoubleSpinBox(layoutWidget1);
        rLight->setObjectName(QString::fromUtf8("rLight"));

        gridLayout_3->addWidget(rLight, 1, 1, 1, 1);

        gLight = new QDoubleSpinBox(layoutWidget1);
        gLight->setObjectName(QString::fromUtf8("gLight"));

        gridLayout_3->addWidget(gLight, 1, 2, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);

        paintLight = new QPushButton(layoutWidget1);
        paintLight->setObjectName(QString::fromUtf8("paintLight"));

        gridLayout_3->addWidget(paintLight, 0, 2, 1, 1);

        aLight = new QDoubleSpinBox(layoutWidget1);
        aLight->setObjectName(QString::fromUtf8("aLight"));

        gridLayout_3->addWidget(aLight, 2, 2, 1, 1);

        bLight = new QDoubleSpinBox(layoutWidget1);
        bLight->setObjectName(QString::fromUtf8("bLight"));

        gridLayout_3->addWidget(bLight, 2, 1, 1, 1);

        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 80, 250, 62));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        xPos = new QDoubleSpinBox(layoutWidget2);
        xPos->setObjectName(QString::fromUtf8("xPos"));

        gridLayout_2->addWidget(xPos, 2, 1, 1, 1);

        yPos = new QDoubleSpinBox(layoutWidget2);
        yPos->setObjectName(QString::fromUtf8("yPos"));

        gridLayout_2->addWidget(yPos, 2, 2, 1, 1);

        zPos = new QDoubleSpinBox(layoutWidget2);
        zPos->setObjectName(QString::fromUtf8("zPos"));

        gridLayout_2->addWidget(zPos, 2, 3, 1, 1);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 1, 1, 1);

        moveLight = new QPushButton(layoutWidget2);
        moveLight->setObjectName(QString::fromUtf8("moveLight"));

        gridLayout_2->addWidget(moveLight, 1, 2, 1, 1);

        tabWidget->addTab(tab, QString());

        horizontalLayout_2->addWidget(tabWidget);


        horizontalLayout->addLayout(horizontalLayout_2);

        contextGL = new GLWidget(centralWidget);
        contextGL->setObjectName(QString::fromUtf8("contextGL"));
        contextGL->setMinimumSize(QSize(600, 0));
        widget = new glwidgetmap(contextGL);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 201, 131));

        horizontalLayout->addWidget(contextGL);

        UIGC2->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(UIGC2);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UIGC2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(UIGC2);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 892, 21));
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

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(UIGC2);
    } // setupUi

    void retranslateUi(QMainWindow *UIGC2)
    {
        UIGC2->setWindowTitle(QApplication::translate("UIGC2", "UIGC2", 0, QApplication::UnicodeUTF8));
        actionBlau->setText(QApplication::translate("UIGC2", "Blau", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("UIGC2", "Load", 0, QApplication::UnicodeUTF8));
        actionFullscreen->setText(QApplication::translate("UIGC2", "Fullscreen", 0, QApplication::UnicodeUTF8));
        actionWindowed->setText(QApplication::translate("UIGC2", "Windowed", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        tab_3->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("UIGC2", "Museums", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("UIGC2", "Objects", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UIGC2", "Potency", 0, QApplication::UnicodeUTF8));
        lightList->clear();
        lightList->insertItems(0, QStringList()
         << QApplication::translate("UIGC2", "Number", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "6", 0, QApplication::UnicodeUTF8)
        );
        addLight->setText(QApplication::translate("UIGC2", "Add", 0, QApplication::UnicodeUTF8));
        deleteLight->setText(QApplication::translate("UIGC2", "Delete", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UIGC2", "Light", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UIGC2", "Color (R, G, B, A)", 0, QApplication::UnicodeUTF8));
        paintLight->setText(QApplication::translate("UIGC2", "Paint", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("UIGC2", "Pos (X, Y, Z)  ", 0, QApplication::UnicodeUTF8));
        moveLight->setText(QApplication::translate("UIGC2", "Move", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UIGC2", "Lights", 0, QApplication::UnicodeUTF8));
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
