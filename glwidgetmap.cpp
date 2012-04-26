#include "glwidgetmap.h"

glwidgetmap* glwidgetmap::instance = NULL;

GLfloat glwidgetmap::translacion_x=0.0f;
GLfloat glwidgetmap::translacion_y=0.0f;
GLfloat glwidgetmap::translacion_z=-0.1f;

glwidgetmap::glwidgetmap(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);
    translacion_x=0.0;
    //translacion_y=0.0;
    //translacion_z=0.0;
}

glwidgetmap::~glwidgetmap(){
    delete(instance);
}

glwidgetmap* glwidgetmap::getInstance() {
    if (!instance) {
        instance = new glwidgetmap();
    }
    return instance;
}

void glwidgetmap::initializeGL() {


    QImage tilesetImage( "data/mapa_museo.jpg");
    QImage anotherImage;
    anotherImage = this->convertToGLFormat( tilesetImage );

    glGenTextures( 1, &textures[0]);
    glBindTexture( GL_TEXTURE_2D, textures[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tilesetImage.width(), tilesetImage.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, anotherImage.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping ( NEW )
    glShadeModel(GL_SMOOTH);                        // Enable Smooth Shading
    glClearColor(1.0f, 1.0f, 0.0f, 0.5f);           // Black Background
    glClearDepth(1.0f);                             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);                        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);                         // The Type Of Depth Testing To Do
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void glwidgetmap::paintGL() {
    glBindTexture(GL_TEXTURE_2D, textures[0]);               // Select Our Texture

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();                           // Reset The Current Matrix

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         // Clear Screen And Depth Buffer

    //Dibujamos la camara
    glColor3f( 0.5, 0.5, 0.5 );


    glPushMatrix();
        glTranslatef(translacion_x,translacion_y,0.0);
        qDebug() << translacion_x;

        glBegin(GL_POLYGON);
                //Dibujamos la forma de una flecha
            glVertex3f(0.0, 0.0, -1.0);
            glVertex3f(-0.1, -0.1, -1.0);
            glVertex3f(0.0, 0.2, -1.0);
            glVertex3f(0.1, -0.1, -1.0);
        glEnd();
    glPopMatrix();

    //Dibujamos el mapa
    glColor3f(1.0f,1.0f,1.0f);//Pintamos de blanco el suelo
    glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);     glVertex3f(-1.0,-1.0,0.0);
            glTexCoord2f(0.0, 1.0);     glVertex3f(-1.0,1.0,0.0);
            glTexCoord2f(1.0, 1.0);     glVertex3f(1.0,1.0,0.0);
            glTexCoord2f(1.0, 0.0);     glVertex3f(1.0,-1.0,0.0);
        glEnd();
    glPopMatrix();

    glFlush();

}

void glwidgetmap::refresh() {
    //setPos(0.1f,0.1f,0.0f);
    translacion_x += 1.1f;
    qDebug() << translacion_x;
    paintGL();

}

void glwidgetmap::setPos(int x, int y, int z){
    /*translacion_x+=10.0;
    translacion_y+=y;
    translacion_z+=z;
    qDebug("Paint");
    qDebug() << translacion_x;
    //qDebug(translacion_y);
    //qDebug(translacion_z);*/
}


