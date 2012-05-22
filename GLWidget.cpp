#include <QtGui/QMouseEvent>
#include <QFileDialog>
#include "GLWidget.h"
#include <iostream>
#include <math.h>
#include <waymanager.h>

using namespace std;

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);
}


/**
Acció: Aquesta funció es crida a l'inicialitzar la finestra per posar a punt l'entorn OpenGL.
Objectiu: Haureu de trobar i saber justificar quines son les funcions a cridar per tal de fer aquesta posta a punt.
Idees: Haureu d'inicialitzar i fer "neteja" d'alguns buffers per tal de fer possible la visualització, haureu de activar o
desactivar alguns flags del pipeline per tal de controlar com es fa el renderitzat
*/
void GLWidget::initializeGL() {

    // ***********************************************************
    // Test de suport OpenGL 2.0 (necess ris per carregar shaders)
#ifndef __APPLE__
    glewInit();

    if (glewIsSupported("GL_VERSION_2_0"))
    {
        printf("Ready for OpenGL 2.0\n");
    }
    else
    {
        printf("OpenGL 2.0 not supported\n");
        exit(1);
    }
#endif
    // ****************************************************
    m_project=true;
    m_viewer=true;
    isMoving = false;
    isZoom = false;

    isMouseReleased = true;

    alphaCamera = 1.0;
    betaCamera = 1.0;
    xCamera = 1.0;
    yCamera = 1.0;

    m_R = 1.0f;
    m_ull_x = 1.0f;
    m_ull_y = 1.0f;
    m_ull_z = 1.0f;

    float w = width();
    float h = height();

    glViewport(0, 0, w, h);

    this->setFocusPolicy(Qt::StrongFocus);  //Necessari pels events de teclat

    //glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);  //Activem el test de profunditat
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);

    //GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //GLfloat mat_shininess[] = { 50.0 };

    glClearColor (0.0, 0.0, 0.0, 0.0);
    //glClearDepth(1.0f);
    //glShadeModel (GL_SMOOTH);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    //glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glLoadIdentity();           //netejar la matriu actual
    //escena->CreateVBO(true);
    model = glmReadOBJ("models/museum_textures2.obj", 1);

    // Exemple ObjectManager
/*
    sgVec3 pos, esc;
    sgQuat rot;

    sgSetVec3(pos,0,15,0); // Posicio del nou objecte
    sgSetVec3(esc,2,2,2); // Escala del nou objecte
    sgMakeIdentQuat(rot); // Rotacio del nou objecte

    ObjectManager::getInstance()->AddObject("cub1",pos,esc,rot,"models/cub.3ds"); // Afegim l'objecte a l'escena

    sgSetVec3(pos,0,-10,1); // Posicio del nou objecte
    sgSetVec3(esc,1,1,1); // Escala del nou objecte
    sgMakeIdentQuat(rot); // Rotacio del nou objecte

    ObjectManager::getInstance()->AddObject("cub2",pos,esc,rot,"models/cub.3ds"); // Afegim l'objecte a l'escena

    sgSetVec3(pos,0,0,0); // Posicio del nou objecte

    ObjectManager::getInstance()->AddObject("cub3",pos,esc,rot,"models/cub.3ds"); // Afegim l'objecte a l'escena

    Object* test = ObjectManager::getInstance()->GetObject("cub1");
    sgPostRotQuat(test->rotacio,45.0,0.0,0.0,1.0); // Rotem el cub1 45 graus, eix z

    // Esborrem el cub3 situat al origen
    ObjectManager::getInstance()->RemoveObject(ObjectManager::getInstance()->GetObject("cub3")->id);

    XMLManager::getInstance()->save("data/data.xml");

    ObjectManager::getInstance()->RemoveAll();

    XMLManager::getInstance()->load("data/data.xml");
*/
}

/**
Acció: Aquesta funció es crida al redimensionar el context OpenGL.
Objectiu: Aquí haurem d'afegir el codi necessari perquè els objectes mostrats en pantalla no es deformin al modificar la
mida d'aquest context.
Idees: Això depèn de com configurem el volum de visualització i els contextos de renderitzat.
*/
void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    CameraControl::getInstance()->ConfigureAspect(float(w)/float(h));
}

/**
Acció: Aquesta funció es crida per dibuixar el contingut del context OpenGL.
Objectiu: Haureu de visualitzar un cub creat per vosaltres amb primitives OpenGL. *No afegiu CAP primitiva referent al
model en aquesta funció*, poseu-les al mètode dibuixa de la classe Model.
Idees: En aquesta funció s'han de re-inicialitzar alguns buffers per no mesclar amb imatges renderitzades amb
anterioritat, configurar el punt de vista de la c mera per si hi ha canvis, cridar a les funcions de dibuixat i finalment
gestionar el re-dibuixat si s'escau.
 */
void GLWidget::paintGL() {


    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpiar buffers

    glColor3f(1,1,1);   //color negro de fondo
    glLoadIdentity();   //limpiar la matriz actual

    /*LightManager::getInstance()->addLight(0,300.0,0.0,0.0);
    LightManager::getInstance()->addLight(1,0.0,300.0,0.0);
    LightManager::getInstance()->addLight(2,0.0,0.0,300.0);
    LightManager::getInstance()->addLight(3,-300.0,0.0,0.0);
    LightManager::getInstance()->addLight(4,0.0,-300.0,0.0);
    LightManager::getInstance()->addLight(5,0.0,0.0,-300.0);*/
    CameraControl::getInstance()->PutCam();
    //glPolygonMode(GL_FRONT, GL_TRIANGLES);
    //escena->Draw();
    //CollisionManager::getInstance()->drawCollision();
    glmDraw(model,GLM_FLAT | GLM_TEXTURE | GLM_MATERIAL);
    //glmDraw(model,GLM_NONE);

    ObjectManager::getInstance()->Draw();
    LightManager::getInstance()->addLight(0);
    LightManager::getInstance()->changePosition(0,CameraControl::getInstance()->getEyex(),CameraControl::getInstance()->getEyey(),CameraControl::getInstance()->getEyez());
    LightManager::getInstance()->addLight(1);
    LightManager::getInstance()->changePosition(1,CameraControl::getInstance()->getEyex()*(-1),CameraControl::getInstance()->getEyey()*(-1),CameraControl::getInstance()->getEyez());

    glFlush();  //Aplica accions
}


/**
Acció: Aquesta funció gestiona els events dels botons del mouse al GLWidget.
Objectiu: Gestionar els botons del ratolí.
*/
void GLWidget::mousePressEvent(QMouseEvent *event) {

    if (event->buttons() & Qt::RightButton) {
        isZoom = true;
        isMouseReleased = false;
        updateGL();
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event) {

    if(event->type() == QEvent::MouseButtonRelease) {
        isMouseReleased = true;
        isMoving = false;
        isZoom = false;
    }
}

/**
Acció: Aquesta funció gestiona els events dels moviments del mouse al GLWidget.
Objectiu: Gestionar el moviment del mouse.
Evitar: http://en.wikipedia.org/wiki/Gimbal_lock
*/
void GLWidget::mouseMoveEvent(QMouseEvent *event) {

    alphaCamera = (alphaCamera + (event->y() - yCamera));
    betaCamera = (betaCamera + (event->x() - xCamera));

    if (event->buttons() & Qt::LeftButton) {
        float w = width()/2;
        float h = height()/2;
        pointer::getInstance()->changePos((w-event->x())/w,(h-event->y())/h);

        updateGL();
    }

    if (isZoom && !isMouseReleased) {
        CameraControl::getInstance()->RotateCam(event->x() - xCamera, event->y() - yCamera);
    }
    xCamera = event->x();
    yCamera = event->y();
    updateGL();
}


/**
Gestiona les tecles polsades quan es troba el focus al widget d'OpenGL.
Objectiu: gestionar els events generats pel teclat.
*/
void GLWidget::keyPressEvent(QKeyEvent* event) {

    switch( event->key() ) {
            case Qt::Key_Up:
            CameraControl::getInstance()->RefreshTarget(0,0,1);
                updateGL();
              break;

            case Qt::Key_Down:
                CameraControl::getInstance()->RefreshTarget(0,0,-1);
                updateGL();
              break;
            case Qt::Key_W:
                glwidgetmap::getInstance()->refresh();
                CameraControl::getInstance()->RefreshTarget(-1,0,0);
                updateGL();
              break;

            case Qt::Key_S:
                CameraControl::getInstance()->RefreshTarget(1,0,0);
                updateGL();
              break;
            case Qt::Key_D:
                CameraControl::getInstance()->RefreshTarget(0,-1,0);
                updateGL();
              break;

            case Qt::Key_A:
                CameraControl::getInstance()->RefreshTarget(0,1,0);
                updateGL();
              break;
            case Qt::Key_Plus:
                      CameraControl::getInstance()->RefreshZoom(-10);
                updateGL();
              break;

            case Qt::Key_Minus:
              CameraControl::getInstance()->RefreshZoom(10);
                updateGL();
              break;
            case Qt::Key_0:
                CameraControl::getInstance()->ChangeVisualMode();
                updateGL();
                break;
            case Qt::Key_1:
                CameraControl::getInstance()->ToggleOnRoute();
                break;
            case Qt::Key_P:
                WayManager::getInstance()->pause();
                break;

    }
}

void GLWidget::SeveralViews(){
    cout << "4 views" << endl;
    m_viewer = false;
    updateGL();
}

void GLWidget::OrthoView(){
    cout << "ortho" << endl;
    m_project = false;
    updateGL();
}

void GLWidget::ProjView(){
    cout << "proj" << endl;
    m_project = true;
    updateGL();

}

void GLWidget::FullView(){
    cout << "full" << endl;
    glViewport(0,0,width(),height());
    m_viewer = true;
    updateGL();
}

void GLWidget::SetBackgroundBlue(){
   glClearColor(0.0,0.0,1.0,0.0);
   updateGL();
}


void GLWidget::LoadFiles(){
    QDir directory;

    QString path = QFileDialog::getExistingDirectory (this, tr("Directory"), directory.path());
    if ( path.isNull() == false )
    {
        directory.setPath(path);
        cout << path.toStdString() << endl;
    }
}

