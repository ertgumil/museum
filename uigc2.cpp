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

void UIGC2::on_pathEdit_textChanged(QString p)
{
        path=p;
}

void UIGC2::on_createNewObjectButton_clicked()
{

        QVector3D pos = QVector3D();
        QVector3D esc = QVector3D(1,1,1);
        QQuaternion rot = QQuaternion();
        QString temppath = path;
        path = QString("models/%1.obj").arg(path);
        qDebug("%s\n",qPrintable(path));


        ObjectManager::getInstance()->AddObject(name,pos,esc,rot,path); // Afegim l'objecte a l'escena

        QComboBox* test = this->findChild<QComboBox*>("comboBoxObjectes");
        test->addItem(name);

        path = temppath;
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
    int id = ObjectManager::getInstance()->getCurrentObject();
    QString name = ObjectManager::getInstance()->GetObject(id)->name.c_str();
    ObjectManager::getInstance()->RemoveObject(id);

    QComboBox* test = this->findChild<QComboBox*>("comboBoxObjectes");
    test->removeItem(test->findText(name));
}

void UIGC2::on_biggerObjectButton_clicked()
{
    int id = ObjectManager::getInstance()->getCurrentObject();
    ObjectManager::getInstance()->GetObject(id)->escala *= 2;
}

void UIGC2::on_smallerObjectButton_clicked()
{
    int id = ObjectManager::getInstance()->getCurrentObject();
    ObjectManager::getInstance()->GetObject(id)->escala /= 2;
}

void UIGC2::on_loadMuseumButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open Document"),
        QDir::currentPath(),
        tr("All files (*.*)") );

    XMLManager::getInstance()->load(filename.toStdString());

}

void UIGC2::on_saveMuseumButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(
            this,
            tr("Save Document"),
            QDir::currentPath(),
            tr("All files (*)") );

    XMLManager::getInstance()->save(filename.toStdString());

}
