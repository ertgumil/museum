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

    alphaCamera = 20.0;
    betaCamera = 79.0;
    xCamera = 79.0;
    yCamera = 20.0;

    m_R = 0.0f;
    m_ull_x = 1.0f;
    m_ull_y = 1.0f;
    m_ull_z = 1.0f;

    float w = width();
    float h = height();

    glViewport(1, 1, w, h);

    this->setFocusPolicy(Qt::StrongFocus);  //Necessari pels events de teclat

    glEnable(GL_DEPTH_TEST);  //Activem el test de profunditat
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);


    glClearColor (0.0, 0.0, 0.0, 0.0);


    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glLoadIdentity();           //netejar la matriu actual
    model = glmReadOBJ("models/museum_textures2.obj", 1);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    CameraControl::getInstance()->ConfigureAspect(float(w)/float(h));
}



void GLWidget::paintGL() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpiar buffers

    glColor3f(1,1,1);   //color negro de fondo
    glLoadIdentity();   //limpiar la matriz actual

    CameraControl::getInstance()->PutCam();
    glmDraw(model,GLM_FLAT | GLM_TEXTURE | GLM_MATERIAL); //dibuixem el MUSEU AQUÍ!!

    ObjectManager::getInstance()->Draw();
    LightManager::getInstance()->addLight(0);
    LightManager::getInstance()->changePosition(0,CameraControl::getInstance()->getEyex(),CameraControl::getInstance()->getEyey(),CameraControl::getInstance()->getEyez());
    LightManager::getInstance()->addLight(1);
    LightManager::getInstance()->changePosition(1,CameraControl::getInstance()->getEyex()*(-1),CameraControl::getInstance()->getEyey()*(-1),CameraControl::getInstance()->getEyez());

    glFlush();  //Aplica accions
}

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

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    alphaCamera = (alphaCamera + (event->y() - yCamera));
    betaCamera = (betaCamera + (event->x() - xCamera));

    if (event->buttons() & Qt::LeftButton) {
        float w = width()/2;
        float h = height()/2;
        int id = ObjectManager::getInstance()->getCurrentObject();
        pointer::getInstance()->changePos((w-event->x())/w,(h-event->y())/h,id);
        updateGL();
    }
    if (isZoom && !isMouseReleased) {
        CameraControl::getInstance()->RotateCam(event->x() - xCamera, event->y() - yCamera);
    }
    xCamera = event->x();
    yCamera = event->y();
    updateGL();
}

void GLWidget::keyPressEvent(QKeyEvent* event) {
    glwidgetmap* test = this->findChild<glwidgetmap*>("minimapaWidget");
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
                test->refresh();
              break;
            case Qt::Key_S:
                glwidgetmap::getInstance()->refresh();
                CameraControl::getInstance()->RefreshTarget(1,0,0);
                updateGL();
                test->refresh();
              break;
            case Qt::Key_D:
                glwidgetmap::getInstance()->refresh();
                CameraControl::getInstance()->RefreshTarget(0,-1,0);
                updateGL();
                test->refresh();
              break;
            case Qt::Key_A:
                glwidgetmap::getInstance()->refresh();
                CameraControl::getInstance()->RefreshTarget(0,1,0);
                updateGL();
                test->refresh();
              break;
            case Qt::Key_Plus:
                CameraControl::getInstance()->RefreshZoom(-10);
                updateGL();
              break;
            case Qt::Key_Minus:
                CameraControl::getInstance()->RefreshZoom(10);
                updateGL();
              break;
            case Qt::Key_Space:
                CameraControl::getInstance()->updateRoute();
                updateGL();
              break;
    }
}

void GLWidget::SeveralViews(){
    cout << "4 views" << endl;
    m_viewer = false;
    updateGL();
}

void GLWidget::OrthoView(){

    cout << "psssss" << endl;
    updateGL();
}

void GLWidget::ProjView(){

    m_project = true;
    updateGL();

}

void GLWidget::FullView(){
    cout << "full" << endl;
    glViewport(0,0,width(),height());
    m_viewer = true;
    updateGL();
}

void GLWidget::ChangeCamera(){

    CameraControl::getInstance()->ChangeVisualMode();
    updateGL();
}

