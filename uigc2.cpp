#include "uigc2.h"
#include "ui_uigc2.h"
#include "lightmanager.h"


UIGC2::UIGC2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIGC2)
{
    ui->setupUi(this);
    ui->tabWidget->setShown(false);
    ui->contextGL->setShown(false);
    ui->controlsWidget->setShown(false);
    ui->minimapaWidget->setShown(false);
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



void UIGC2::on_createNewObjectButton_clicked()
{

        QVector3D pos = QVector3D();
        QVector3D esc = QVector3D(1,1,1);
        QQuaternion rot = QQuaternion();

            QString path = QFileDialog::getOpenFileName(
                this,
                tr("Open Document"),
                "models",
                tr("Obj Files (*.obj)") );

            ObjectManager::getInstance()->AddObject(name,pos,esc,rot,path); // Afegim l'objecte a l'escena

            QComboBox* test = this->findChild<QComboBox*>("comboBoxObjectes");
            test->addItem(name);

}

void UIGC2::on_nameEdit_textChanged(QString n)
{
        name=n;
}

void UIGC2::on_comboBoxObjectes_currentIndexChanged(const QString &arg1)
{
    //GLWidget* test = this->findChild<GLWidget*>("contextGL");
    //test->setCurrentObject(arg1);
    ObjectManager::getInstance()->setCurrentObject(ObjectManager::getInstance()->GetObject(arg1.toStdString())->id);
}

void UIGC2::on_comboBoxObjectes_highlighted(const QString &arg1)
{
    ObjectManager::getInstance()->setCurrentObject(ObjectManager::getInstance()->GetObject(arg1.toStdString())->id);
}

void UIGC2::on_deleteObjectButton_clicked()
{
    int id = ObjectManager::getInstance()->getId();
    if(id > 0) {
        QString name = ObjectManager::getInstance()->GetObject(id)->name.c_str();
        ObjectManager::getInstance()->RemoveObject(id);

        //QComboBox* test = this->findChild<QComboBox*>("comboBoxObjectes");
        //test->removeItem(test->findText(name));
    }
}

void UIGC2::on_loadMuseumButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open Document"),
        "data",
        tr("All files (*.xml)") );

    XMLManager::getInstance()->load(filename.toStdString());

}

void UIGC2::on_saveMuseumButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(
            this,
            tr("Save Document"),
            "data",
            tr("XML files (*.xml)") );

    XMLManager::getInstance()->save(filename.toStdString());
}

void UIGC2::on_sizeSlider_valueChanged(int value)
{
    int id = ObjectManager::getInstance()->currentobject;
    if(id > 0) {
            if(value==3)
            ObjectManager::getInstance()->GetObject(id)->escala *= 2;
        else if(value==1)
            ObjectManager::getInstance()->GetObject(id)->escala /= 2;
    }
}

void UIGC2::on_rotationSlider_valueChanged(int value)
{
    int id = ObjectManager::getInstance()->currentobject;
    if(id > 0) {
        ObjectManager::getInstance()->GetObject(id)->rotacio *= QQuaternion::fromAxisAndAngle(QVector3D(0,0,1),90);
    }
}

void UIGC2::on_editorButton_released()
{
    ui->menuWidget->setShown(false); //oculta el menu per triar el mode
    ui->tabWidget->setShown(true);   //mostra el panell de botons
    ui->contextGL->setShown(true); //activa el museu
}

void UIGC2::on_visitantButton_released()
{
    ui->menuWidget->setShown(false); //oculta el menu per triar el mode
    ui->contextGL->setShown(true); //activa el museu
    CameraControl::getInstance()->ChangeVisualMode();
    XMLManager::getInstance()->load("data/museum2.xml");
}

void UIGC2::on_controlsButton_released()
{
    ui->controlsWidget->setShown(false);    //desactiva el menu de controls
}
