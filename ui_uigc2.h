/********************************************************************************
** Form generated from reading UI file 'uigc2.ui'
**
** Created: Mon May 28 17:19:37 2012
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
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
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
    QAction *actionPrimera_persona;
    QAction *actionTercera_persona;
    QAction *actionControls;
    QAction *actionComen_a_Ruta;
    QAction *actionAcaba_Ruta;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *BotonsLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QPushButton *loadMuseumButton;
    QPushButton *saveMuseumButton;
    QWidget *tab_4;
    QPushButton *createNewObjectButton;
    QLineEdit *nameEdit;
    QLabel *nameLabel;
    QComboBox *comboBoxObjectes;
    QLabel *label;
    QPushButton *deleteObjectButton;
    QSlider *sizeSlider;
    QSlider *rotationSlider;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *lightList;
    QPushButton *addLight;
    QLabel *label_3;
    QPushButton *deleteLight;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *rLight;
    QPushButton *paintLight;
    QDoubleSpinBox *bLight;
    QPushButton *moveLight;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *zPos;
    QDoubleSpinBox *xPos;
    QDoubleSpinBox *aLight;
    QDoubleSpinBox *gLight;
    QDoubleSpinBox *yPos;
    QWidget *menuWidget;
    QPushButton *editorButton;
    QPushButton *visitantButton;
    QGraphicsView *graphicsView;
    GLWidget *contextGL;
    glwidgetmap *minimapaWidget;
    QWidget *controlsWidget;
    QRadioButton *controlsButton;
    QMenuBar *menuBar;
    QMenu *menuOpcions;
    QMenu *menuView;
    QMenu *menuAjuda;
    QMenu *menuRutes;
    QStatusBar *statusBar;

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
        actionPrimera_persona = new QAction(UIGC2);
        actionPrimera_persona->setObjectName(QString::fromUtf8("actionPrimera_persona"));
        actionTercera_persona = new QAction(UIGC2);
        actionTercera_persona->setObjectName(QString::fromUtf8("actionTercera_persona"));
        actionControls = new QAction(UIGC2);
        actionControls->setObjectName(QString::fromUtf8("actionControls"));
        actionComen_a_Ruta = new QAction(UIGC2);
        actionComen_a_Ruta->setObjectName(QString::fromUtf8("actionComen_a_Ruta"));
        actionAcaba_Ruta = new QAction(UIGC2);
        actionAcaba_Ruta->setObjectName(QString::fromUtf8("actionAcaba_Ruta"));
        centralWidget = new QWidget(UIGC2);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        BotonsLayout = new QHBoxLayout();
        BotonsLayout->setSpacing(0);
        BotonsLayout->setContentsMargins(0, 0, 0, 0);
        BotonsLayout->setObjectName(QString::fromUtf8("BotonsLayout"));
        BotonsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(250, 0));
        tabWidget->setMaximumSize(QSize(250, 16777215));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        loadMuseumButton = new QPushButton(tab_3);
        loadMuseumButton->setObjectName(QString::fromUtf8("loadMuseumButton"));
        loadMuseumButton->setGeometry(QRect(60, 100, 97, 27));
        saveMuseumButton = new QPushButton(tab_3);
        saveMuseumButton->setObjectName(QString::fromUtf8("saveMuseumButton"));
        saveMuseumButton->setGeometry(QRect(60, 180, 97, 27));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        createNewObjectButton = new QPushButton(tab_4);
        createNewObjectButton->setObjectName(QString::fromUtf8("createNewObjectButton"));
        createNewObjectButton->setGeometry(QRect(60, 60, 85, 27));
        nameEdit = new QLineEdit(tab_4);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(90, 10, 113, 25));
        nameLabel = new QLabel(tab_4);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(10, 20, 58, 15));
        comboBoxObjectes = new QComboBox(tab_4);
        comboBoxObjectes->setObjectName(QString::fromUtf8("comboBoxObjectes"));
        comboBoxObjectes->setGeometry(QRect(10, 150, 221, 27));
        comboBoxObjectes->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 0, 0);"));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 130, 131, 16));
        deleteObjectButton = new QPushButton(tab_4);
        deleteObjectButton->setObjectName(QString::fromUtf8("deleteObjectButton"));
        deleteObjectButton->setGeometry(QRect(10, 200, 85, 27));
        sizeSlider = new QSlider(tab_4);
        sizeSlider->setObjectName(QString::fromUtf8("sizeSlider"));
        sizeSlider->setGeometry(QRect(30, 280, 160, 23));
        sizeSlider->setMinimum(1);
        sizeSlider->setMaximum(3);
        sizeSlider->setValue(2);
        sizeSlider->setOrientation(Qt::Horizontal);
        rotationSlider = new QSlider(tab_4);
        rotationSlider->setObjectName(QString::fromUtf8("rotationSlider"));
        rotationSlider->setGeometry(QRect(30, 340, 160, 23));
        rotationSlider->setMaximum(4);
        rotationSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 250, 31, 16));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 280, 16, 16));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(190, 280, 16, 16));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 320, 58, 15));
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
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 241, 95));
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

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        deleteLight = new QPushButton(layoutWidget);
        deleteLight->setObjectName(QString::fromUtf8("deleteLight"));

        gridLayout->addWidget(deleteLight, 1, 2, 1, 1);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 140, 251, 95));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 80, 250, 62));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        rLight = new QDoubleSpinBox(tab);
        rLight->setObjectName(QString::fromUtf8("rLight"));
        rLight->setGeometry(QRect(10, 205, 122, 25));
        paintLight = new QPushButton(tab);
        paintLight->setObjectName(QString::fromUtf8("paintLight"));
        paintLight->setGeometry(QRect(138, 171, 101, 27));
        bLight = new QDoubleSpinBox(tab);
        bLight->setObjectName(QString::fromUtf8("bLight"));
        bLight->setGeometry(QRect(10, 237, 122, 25));
        moveLight = new QPushButton(tab);
        moveLight->setObjectName(QString::fromUtf8("moveLight"));
        moveLight->setGeometry(QRect(94, 110, 85, 27));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 78, 27));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 171, 122, 27));
        zPos = new QDoubleSpinBox(tab);
        zPos->setObjectName(QString::fromUtf8("zPos"));
        zPos->setGeometry(QRect(185, 143, 73, 25));
        xPos = new QDoubleSpinBox(tab);
        xPos->setObjectName(QString::fromUtf8("xPos"));
        xPos->setGeometry(QRect(10, 143, 78, 25));
        aLight = new QDoubleSpinBox(tab);
        aLight->setObjectName(QString::fromUtf8("aLight"));
        aLight->setGeometry(QRect(138, 237, 121, 25));
        gLight = new QDoubleSpinBox(tab);
        gLight->setObjectName(QString::fromUtf8("gLight"));
        gLight->setGeometry(QRect(138, 205, 121, 25));
        yPos = new QDoubleSpinBox(tab);
        yPos->setObjectName(QString::fromUtf8("yPos"));
        yPos->setGeometry(QRect(94, 143, 85, 25));
        tabWidget->addTab(tab, QString());

        BotonsLayout->addWidget(tabWidget);


        horizontalLayout->addLayout(BotonsLayout);

        menuWidget = new QWidget(centralWidget);
        menuWidget->setObjectName(QString::fromUtf8("menuWidget"));
        menuWidget->setEnabled(true);
        menuWidget->setMinimumSize(QSize(0, 0));
        menuWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        editorButton = new QPushButton(menuWidget);
        editorButton->setObjectName(QString::fromUtf8("editorButton"));
        editorButton->setGeometry(QRect(80, 330, 121, 51));
        editorButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"font: 14pt \"Lucida Grande\";\n"
"color: rgb(255, 255, 255);"));
        visitantButton = new QPushButton(menuWidget);
        visitantButton->setObjectName(QString::fromUtf8("visitantButton"));
        visitantButton->setGeometry(QRect(80, 280, 121, 51));
        visitantButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"font: 14pt \"Lucida Grande\";\n"
"color: rgb(255, 255, 255);"));
        visitantButton->setDefault(false);
        graphicsView = new QGraphicsView(menuWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 886, 520));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/menu.png);"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setLineWidth(0);
        graphicsView->setInteractive(false);
        graphicsView->raise();
        editorButton->raise();
        visitantButton->raise();

        horizontalLayout->addWidget(menuWidget);

        contextGL = new GLWidget(centralWidget);
        contextGL->setObjectName(QString::fromUtf8("contextGL"));
        contextGL->setMinimumSize(QSize(0, 0));
        minimapaWidget = new glwidgetmap(contextGL);
        minimapaWidget->setObjectName(QString::fromUtf8("minimapaWidget"));
        minimapaWidget->setGeometry(QRect(10, 10, 201, 131));
        controlsWidget = new QWidget(contextGL);
        controlsWidget->setObjectName(QString::fromUtf8("controlsWidget"));
        controlsWidget->setGeometry(QRect(10, 150, 248, 96));
        controlsWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/images/controls.png);"));
        controlsButton = new QRadioButton(controlsWidget);
        controlsButton->setObjectName(QString::fromUtf8("controlsButton"));
        controlsButton->setGeometry(QRect(0, 0, 16, 21));
        controlsButton->setContextMenuPolicy(Qt::NoContextMenu);
        controlsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(contextGL);

        UIGC2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UIGC2);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 892, 21));
        menuBar->setMinimumSize(QSize(10, 10));
        menuOpcions = new QMenu(menuBar);
        menuOpcions->setObjectName(QString::fromUtf8("menuOpcions"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        menuRutes = new QMenu(menuBar);
        menuRutes->setObjectName(QString::fromUtf8("menuRutes"));
        UIGC2->setMenuBar(menuBar);
        statusBar = new QStatusBar(UIGC2);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UIGC2->setStatusBar(statusBar);

        menuBar->addAction(menuOpcions->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuRutes->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuOpcions->addAction(actionPrimera_persona);
        menuOpcions->addAction(actionTercera_persona);
        menuView->addAction(actionFullscreen);
        menuView->addAction(actionWindowed);
        menuAjuda->addAction(actionControls);
        menuRutes->addAction(actionComen_a_Ruta);
        menuRutes->addAction(actionAcaba_Ruta);

        retranslateUi(UIGC2);
        QObject::connect(actionFullscreen, SIGNAL(triggered()), UIGC2, SLOT(showFullScreen()));
        QObject::connect(actionWindowed, SIGNAL(triggered()), UIGC2, SLOT(showMaximized()));
        QObject::connect(actionPrimera_persona, SIGNAL(triggered()), contextGL, SLOT(ChangeCamera()));
        QObject::connect(actionTercera_persona, SIGNAL(triggered()), contextGL, SLOT(ChangeCamera()));
        QObject::connect(sizeSlider, SIGNAL(sliderMoved(int)), contextGL, SLOT(update()));
        QObject::connect(rotationSlider, SIGNAL(sliderMoved(int)), contextGL, SLOT(update()));
        QObject::connect(createNewObjectButton, SIGNAL(released()), contextGL, SLOT(update()));
        QObject::connect(deleteObjectButton, SIGNAL(released()), contextGL, SLOT(update()));
        QObject::connect(actionControls, SIGNAL(triggered()), controlsWidget, SLOT(show()));
        QObject::connect(actionPrimera_persona, SIGNAL(triggered()), minimapaWidget, SLOT(show()));
        QObject::connect(actionTercera_persona, SIGNAL(triggered()), minimapaWidget, SLOT(hide()));
        QObject::connect(createNewObjectButton, SIGNAL(released()), contextGL, SLOT(update()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(UIGC2);
    } // setupUi

    void retranslateUi(QMainWindow *UIGC2)
    {
        UIGC2->setWindowTitle(QApplication::translate("UIGC2", "UIGC2", 0, QApplication::UnicodeUTF8));
        actionBlau->setText(QApplication::translate("UIGC2", "Blau", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("UIGC2", "Load", 0, QApplication::UnicodeUTF8));
        actionFullscreen->setText(QApplication::translate("UIGC2", "Fullscreen", 0, QApplication::UnicodeUTF8));
        actionWindowed->setText(QApplication::translate("UIGC2", "Windowed", 0, QApplication::UnicodeUTF8));
        actionPrimera_persona->setText(QApplication::translate("UIGC2", "Primera persona", 0, QApplication::UnicodeUTF8));
        actionTercera_persona->setText(QApplication::translate("UIGC2", "Tercera persona", 0, QApplication::UnicodeUTF8));
        actionControls->setText(QApplication::translate("UIGC2", "Controls", 0, QApplication::UnicodeUTF8));
        actionComen_a_Ruta->setText(QApplication::translate("UIGC2", "Comen\303\247a Ruta", 0, QApplication::UnicodeUTF8));
        actionAcaba_Ruta->setText(QApplication::translate("UIGC2", "Acaba Ruta", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        tab_3->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        loadMuseumButton->setText(QApplication::translate("UIGC2", "Carregar", 0, QApplication::UnicodeUTF8));
        saveMuseumButton->setText(QApplication::translate("UIGC2", "Guardar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("UIGC2", "Museus", 0, QApplication::UnicodeUTF8));
        createNewObjectButton->setText(QApplication::translate("UIGC2", "Crear", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("UIGC2", "Nom", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UIGC2", "Selecciona un objecte", 0, QApplication::UnicodeUTF8));
        deleteObjectButton->setText(QApplication::translate("UIGC2", "Elimina", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UIGC2", "Mida", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("UIGC2", "-", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("UIGC2", "+", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("UIGC2", "Rotacio", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("UIGC2", "Objectes", 0, QApplication::UnicodeUTF8));
        lightList->clear();
        lightList->insertItems(0, QStringList()
         << QApplication::translate("UIGC2", "Numero de llum", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UIGC2", "6", 0, QApplication::UnicodeUTF8)
        );
        addLight->setText(QApplication::translate("UIGC2", "Afegir", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UIGC2", "Llum", 0, QApplication::UnicodeUTF8));
        deleteLight->setText(QApplication::translate("UIGC2", "Eliminar", 0, QApplication::UnicodeUTF8));
        paintLight->setText(QApplication::translate("UIGC2", "Pintar", 0, QApplication::UnicodeUTF8));
        moveLight->setText(QApplication::translate("UIGC2", "Moure", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("UIGC2", "Pos (X, Y, Z)  ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UIGC2", "Color (R, G, B, A)", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UIGC2", "Llums", 0, QApplication::UnicodeUTF8));
        editorButton->setText(QApplication::translate("UIGC2", "Editor", 0, QApplication::UnicodeUTF8));
        visitantButton->setText(QApplication::translate("UIGC2", "Visitant", 0, QApplication::UnicodeUTF8));
        controlsButton->setText(QApplication::translate("UIGC2", "OK", 0, QApplication::UnicodeUTF8));
        menuOpcions->setTitle(QApplication::translate("UIGC2", "Camara", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("UIGC2", "Vista", 0, QApplication::UnicodeUTF8));
        menuAjuda->setTitle(QApplication::translate("UIGC2", "Ajuda", 0, QApplication::UnicodeUTF8));
        menuRutes->setTitle(QApplication::translate("UIGC2", "Rutes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UIGC2: public Ui_UIGC2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIGC2_H
