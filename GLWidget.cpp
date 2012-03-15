#include <QtGui/QMouseEvent>
#include "GLWidget.h"
#include <iostream>
#include <math.h>

using namespace std;

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);
    escena = new CModel3DS("Sala1.3ds");
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

    /*
    // ****************************************************
    // C rrega dels shaders (per a les pr ctiques 2, 3 i 4)
    bool result;
    result = m_shader.addShaderFromSourceFile( QGLShader::Vertex, "./simple.vert" );
    if ( !result )
        qDebug() << "Vertex: " << m_shader.log();
    else
        qDebug() << "Vertex shader works!";
    result = m_shader.addShaderFromSourceFile( QGLShader::Fragment, "./simple.frag" );
    if ( !result )
        qDebug() << "Fragment: " << m_shader.log();
    else
        qDebug() << "Fragment shader works!";
    result = m_shader.link();
    if ( !result )
        qDebug() << "Link: " << m_shader.log();
    else
        qDebug() << "Shaders link: OK!";
    result = m_shader.bind();
    if ( !result )
        qDebug() << "Bind: " << m_shader.log();
    else
        qDebug() << "Shaders bind: OK!";
    // ****************************************************
    */


    //CameraControl::getInstance()->ChangeVisualMode();

    this->setFocusPolicy(Qt::StrongFocus);  //Necessari pels events de teclat

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);  //Activem el test de profunditat
    glShadeModel(GL_SMOOTH);

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    GLfloat pos[] = {300.0, 300.0, 300.0};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);


   // project(0.0f, 5.0f, 5.0f);

    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glLoadIdentity();           //netejar la matriu actual
    escena->CreateVBO();

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
   // project(5.0f, 5.0f, 5.0f);
    //glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
   // glLoadIdentity();           //netejar la matriu actual
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



    CameraControl::getInstance()->PutCam();
    //Model::getInstance()->DibuixaGrid();
    //Model::getInstance()->DibuixaCub();

    glPolygonMode(GL_FRONT, GL_TRIANGLES);
    escena->Draw();

    glFlush();  //Aplica accions
}


/**
Acció: Aquesta funció gestiona els events dels botons del mouse al GLWidget.
Objectiu: Gestionar els botons del ratolí.
*/
void GLWidget::mousePressEvent(QMouseEvent *event) {

    if (event->buttons() & Qt::LeftButton) {
        isMoving = true;
        isMouseReleased = false;
        updateGL();
    }

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

    if(isMoving && !isMouseReleased) {
        /*m_ull_x = cos(alphaCamera*3.14/180)*cos(betaCamera*3.14/180);
        m_ull_y = sin(alphaCamera*3.14/180)*cos(betaCamera*3.14/180);
        m_ull_z = sin(betaCamera*3.14/180);*/
        //cout<< "clicked  " <<   float(int(betaCamera)%360) <<endl;

        //CameraControl::getInstance()->RotateCam(event->x() - xCamera);


    }

    if (isZoom && !isMouseReleased) {
        CameraControl::getInstance()->RotateCam(event->x() - xCamera);
    }
    xCamera = event->x();
    yCamera = event->y();
    //CameraControl::getInstance()->ViewCam(event->x() - xCamera,event->y() - yCamera);
    updateGL();
}


/**
Gestiona les tecles polsades quan es troba el focus al widget d'OpenGL.
Objectiu: gestionar els events generats pel teclat.
*/
void GLWidget::keyPressEvent(QKeyEvent* event) {

    switch( event->key() ) {
        /*case Qt::Key_Up:
            m_ull_x  = m_R*cos((alphaCamera+10)*3.14/180)*cos((alphaCamera+10)*3.14/180);
            cout << "L" << endl;
            updateGL();
          break;

        case Qt::Key_Down:
        //m_ull_x  = m_R*cos(1*3.14/180)*cos(1*3.14/180);
            cout << "F" << endl;
            updateGL();
          break;
        case Qt::Key_Right:
            m_ull_z += 1;
            cout << "L" << endl;
            updateGL();
          break;

        case Qt::Key_Left:
            m_ull_z -= 1;
            cout << "F" << endl;

            updateGL();
          break;

        case Qt::Key_Plus:
            m_R +=3 ;
            updateGL();
          break;

        case Qt::Key_Minus:
            m_R -=3 ;
            updateGL();
          break;*/
            case Qt::Key_Up:
            CameraControl::getInstance()->RefreshTarget(-1,0,0);
                updateGL();
              break;

            case Qt::Key_Down:
                CameraControl::getInstance()->RefreshTarget(1,0,0);
                updateGL();
              break;
            case Qt::Key_Right:
                 CameraControl::getInstance()->RefreshTarget(0,-1,0);
                 updateGL();
              break;

            case Qt::Key_Left:
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

    }
}

void GLWidget::project(float x, float y, float z)
{
    float w = width();
    float h = height();
    float pos[3] = {0.0f,0.0f,0.0f};
    float BB[6] = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
    float diagonal;
    float k = w/h;
    float R = 1.0f;
    //1. Centrem L'objecte
    //Model::getInstance()->Torna_Desp(pos);
    glTranslatef(-pos[0],-pos[1],-pos[2]);

    //2. Carreguem BoundingBox
    //Model::getInstance()->BoundingBox(BB);

    //3. Calcul de la diagonal.
    pos[0] = BB[3] - BB[0];
    pos[1] = BB[4] - BB[1];
    pos[2] = BB[5] - BB[2];

    pos[0] = pos[0] * pos[0];
    pos[1] = pos[1] * pos[1];
    pos[2] = pos[2] * pos[2];

    diagonal = sqrt(pos[0]+pos[1]+pos[2]);
    //4. Definim glOrtho
    glMatrixMode(GL_PROJECTION);    //escollim treballar amb la matriu PROJECTION
    glLoadIdentity();               //netejar la matriu actual


    if(m_project){
        float alpha =30.0f;
        float rads = alpha*3.14/180;
        float r = diagonal/2;
        R = (r/sin(rads/2))+0.1f + m_R;
        gluPerspective(alpha, w / h, 0.1f, 2*R+m_R);
    }

    else{
        R=1.0f;
        //5. calcul del radi
        float r=sqrt(3.0)/2;

        //escalat
        float FE = 2*r/(diagonal+m_R);

        glOrtho(-k,k,-1,1,-2,50.0f);  //per veure el cub sencer. TODO ¿Deformacion?

        if (FE< 1.0f) glScalef(FE, FE, FE);
        else {
            FE=1/FE;
            glScalef(FE, FE, FE);
        }
    }
    //cout << x << " " << y << " " << z << " " << m_R << endl;
    if ((y > 0.0f)&&(x==0.0f)&&(z==0.0f)) gluLookAt(R*x,R*y,R*z, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    else gluLookAt(R*x,R*y,R*z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}


void GLWidget::view4(){  ///funció per fer les 4 vistes. Punt 8.
   int w = width();
   int h = height();

   int w_middle = w/2;
   int h_middle = h/2;

   int w_marg = w/2;
   int h_marg = h/2;


   glEnable(GL_SCISSOR_TEST);

    ///////////////////////////////////////////Finestra 1//////////////////////////////////
    project(0.0f,1.0f, 0.0f);//escollim a on mirem: PLANTA

    //gluLookAt(0.0f,1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);

    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glViewport(0,h_middle,w_middle,h-h_marg); //Finestra 1, - 100 perque deixar marge.
    glScissor(0,h_middle,w_middle,h-h_marg);
    glLoadIdentity();           //netejar la matriu actual
    glClear(GL_COLOR_BUFFER_BIT);
    //Model::getInstance()->DibuixaCub();

    //////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////Finestra 2//////////////////////////////////

    project(1.0f, 0.0f, 0.0f);
    //gluLookAt(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);    //escollim a on mirem:ALÇAT

    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glLoadIdentity();           //netejar la matriu actual
    glViewport(w_middle,h_middle,w-w_marg,h-h_marg); //Finestra 2, - 100 perque deixar marge.
    glScissor  ( w_middle,h_middle,w-w_marg,h-h_marg);
    glClear(GL_COLOR_BUFFER_BIT);
    //Model::getInstance()->DibuixaCub();
    //////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////Finestra 3//////////////////////////////////
    project(0.0f,0.0f, 1.0f);
    //gluLookAt(0.0f,0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);    //escollim a on mirem:Perfil

    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glViewport(0,0,w_middle,h_middle); //Finestra 3.
    glScissor(0,0,w_middle,h_middle);
    glLoadIdentity();           //netejar la matriu actual
    glClear(GL_COLOR_BUFFER_BIT);
    //Model::getInstance()->DibuixaCub();

    //////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////Finestra 4//////////////////////////////////
    project(1.0f, 1.0f, 1.0f);
    //gluLookAt(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);    //escollim a on mirem

    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glLoadIdentity();           //netejar la matriu actual
    glViewport(w_middle,0,w-w_marg,h_middle); //Finestra 4
    glScissor(w_middle,0,w-w_marg,h_middle);
    glClear(GL_COLOR_BUFFER_BIT);
    //Model::getInstance()->DibuixaCub();
    //////////////////////////////////////////////////////////////////////////////////////////

    glDisable(GL_SCISSOR_TEST);

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


