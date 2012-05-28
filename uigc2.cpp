#include "uigc2.h"
#include "ui_uigc2.h"
#include "lightmanager.h"
#include "xmlruta.h"


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
    activeLight = index; //-1 pq aixi tenim el 1r de la llista que no es cap llum al frame
}

void UIGC2::on_addLight_clicked()   //un cop clicat Add
{
    LightManager::getInstance()->addLight(activeLight);
    ui->contextGL->updateGL();
}

void UIGC2::on_deleteLight_clicked() //un cop clicat Delete
{
    LightManager::getInstance()->deleteLight(activeLight);
    ui->contextGL->updateGL();
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
    LightManager::getInstance()->changePosition(activeLight, ui->xPos->value(), ui->yPos->value(), ui->zPos->value());
    ui->contextGL->updateGL();
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
    LightManager::getInstance()->changeColor(activeLight, ui->rLight->value(), ui->gLight->value(), ui->bLight->value(), ui->aLight->value());
    ui->contextGL->updateGL();
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

    bool minimapa = !ui->minimapaWidget->isHidden();

    if (minimapa) ui->minimapaWidget->setShown(false);

    ui->contextGL->updateGL();
    ObjectManager::getInstance()->AddObject(name,pos,esc,rot,path); // Afegim l'objecte a l'escena

    ui->comboBoxObjectes->addItem(name);
    int id = ui->comboBoxObjectes->findText(name);
    ui->comboBoxObjectes->setCurrentIndex(id);

    if (minimapa) ui->minimapaWidget->setShown(true);

}

void UIGC2::on_nameEdit_textChanged(QString n)
{
        name=n;
}

void UIGC2::on_comboBoxObjectes_currentIndexChanged(const QString &arg1)
{
    if(!arg1.isEmpty())
        ObjectManager::getInstance()->setCurrentObject(ObjectManager::getInstance()->GetObject(arg1.toStdString())->id);
}

void UIGC2::on_comboBoxObjectes_highlighted(const QString &arg1)
{
    if(!arg1.isEmpty())
        ObjectManager::getInstance()->setCurrentObject(ObjectManager::getInstance()->GetObject(arg1.toStdString())->id);
}

void UIGC2::on_deleteObjectButton_clicked()
{
    int id = ObjectManager::getInstance()->getId();
    QString nomCombo = ui->comboBoxObjectes->currentText();

    std::string nom;
    nom = nomCombo.toStdString();

    if(id > 0) {
        int id = ObjectManager::getInstance()->GetObject(nom)->id;
        ObjectManager::getInstance()->RemoveObject(id);
        int borrar = ui->comboBoxObjectes->findText(nomCombo);
        ui->comboBoxObjectes->removeItem(borrar);
    }
}

void UIGC2::on_loadMuseumButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open Document"),
        "data",
        tr("All files (*.xml)") );

     ObjectManager::getInstance()->RemoveAll();
     ui->comboBoxObjectes->clear();

    if(filename.length() > 0){
           XMLManager::getInstance()->load(filename.toStdString(),ui->comboBoxObjectes);
    }

}

void UIGC2::on_saveMuseumButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(
            this,
            tr("Save Document"),
            "data",
            tr("XML files (*.xml)") );

    XMLManager::getInstance()->save(filename.toStdString());
    XMLManager::getInstance()->save("data/default.xml");
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


    //ui->contextGL->updateGL();
    XMLManager::getInstance()->load("data/default.xml",ui->comboBoxObjectes);
    pointer::getInstance()->visitantOn();

    CameraControl::getInstance()->ChangeVisualMode();
    ui->minimapaWidget->setShown(true);
}

void UIGC2::on_controlsButton_released()
{
    ui->controlsWidget->setShown(false);    //desactiva el menu de controls
}

void UIGC2::on_actionComen_a_Ruta_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open Route"),
        "data",
        tr("All files (*.xml)") );

    xmlRuta::getInstance()->load((filename.toStdString()));
    CameraControl::getInstance()->StartRoute();
}

void UIGC2::on_actionAcaba_Ruta_triggered()
{
   CameraControl::getInstance()->StopRoute();
}

void UIGC2::on_tabWidget_currentChanged(int index)
{
    if (index == 1)
        LightManager::getInstance()->mode = 0;
    if (index == 2)
        LightManager::getInstance()->mode = 1;
}

void UIGC2::on_lightList_currentIndexChanged(int index)
{
    activeLight = index;
    LightManager::getInstance()->currentLight = index;
}

void UIGC2::on_lightList_highlighted(int index)
{
    activeLight = index;
    LightManager::getInstance()->currentLight = index;
}
