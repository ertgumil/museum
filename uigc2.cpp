#include "uigc2.h"
#include "ui_uigc2.h"
#include "lightmanager.h"


UIGC2::UIGC2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIGC2)
{
    ui->setupUi(this);
}

UIGC2::~UIGC2()
{
    delete ui;
}

void UIGC2::on_lightList_activated(int index)   //ens diu sobre quina llum treballem
{
    activeLight = index-1; //-1 pq aixi tenim el 1r de la llista que no es cap llum al frame
}

void UIGC2::on_addLight_clicked()   //un cop clicat Add
{
    LightManager::getInstance()->addLight(activeLight);
}

void UIGC2::on_deleteLight_clicked() //un cop clicat Delete
{
    LightManager::getInstance()->deleteLight(activeLight);
}

void UIGC2::on_xPos_valueChanged(double x)  //nova posicio de la X
{
    newX = x;
}

void UIGC2::on_yPos_valueChanged(double y) //nova posicio de la Y
{
    newY = y;
}

void UIGC2::on_zPos_valueChanged(double z) //nova posicio de la Z
{
    newZ = z;
}

void UIGC2::on_moveLight_clicked()  //un cop clicat Move
{
    LightManager::getInstance()->changePosition(activeLight, newX, newY, newZ);
}

void UIGC2::on_rLight_valueChanged(double r)    //nova R del color
{
    newR = r;
}

void UIGC2::on_gLight_valueChanged(double g)    //nova G del color
{
    newG = g;
}

void UIGC2::on_bLight_valueChanged(double b)    //nova B del color
{
    newB = b;
}

void UIGC2::on_aLight_valueChanged(double a)    //nova Alpha del color
{
    newA = a;
}

void UIGC2::on_paintLight_clicked() //un cop clicat Paint
{
    LightManager::getInstance()->changeColor(activeLight, newR, newG, newB, newA);
}

void UIGC2::on_pathEdit_returnPressed()
{
    finished=true;
}

void UIGC2::on_pathEdit_textChanged(QString p)
{
    if(finished){
        path=p;
    }
}

void UIGC2::on_createNewObjectButton_clicked()
{
    qDebug("%s\n",qPrintable(path));
    if (finished && finished2)
    {
        sgVec3 pos;
        sgQuat rot;
        sgVec3 esc;

        pos[0]=0.0;
        pos[1]=0.0;
        pos[2]=0.0;

        sgSetVec3(esc,1,1,1); // Escala del nou objecte
        sgMakeIdentQuat(rot); // Rotacio del nou objecte

        ObjectManager::getInstance()->AddObject(name,pos,esc,rot,path); // Afegim l'objecte a l'escena
    }
}

void UIGC2::on_nameEdit_returnPressed()
{
   finished2=true;
}

void UIGC2::on_nameEdit_textChanged(QString n)
{
    if(finished2){
        name=n;
    }
}
