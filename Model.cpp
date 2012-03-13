#include "Model.h"

Model::Model(){

}

Model::~Model(){
	
}

void Model::Dibuixa(){

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);       // Trasera
        glVertex3f( -0.5f, -0.5f,  -0.5f);
        glVertex3f( 0.5f, -0.5f,  -0.5f);
        glVertex3f( 0.5f,  0.5f,  -0.5f);
        glVertex3f(-0.5f,  0.5f,  -0.5f);
    glEnd();


    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);       // Lateral Izquierdo
        glVertex3f( -0.5f, -0.5f,  -0.5f);
        glVertex3f( -0.5f, 0.5f,  -0.5f);
        glVertex3f( -0.5f,  0.5f,  0.5f);
        glVertex3f(-0.5f,  -0.5f,  0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);       // Inferior
        glVertex3f( -0.5f, -0.5f,     -0.5f);
        glVertex3f( 0.5f, -0.5f,  -0.5f);
        glVertex3f( 0.5f,  -0.5f,  0.5f);
        glVertex3f(-0.5f,  -0.5f,  0.5f);
    glEnd();

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);       // Lateral derecho
        glVertex3f( 0.5f, -0.5f,  -0.5f);
        glVertex3f( 0.5f, 0.5f,  -0.5f);
        glVertex3f( 0.5f,  0.5f,  0.5f);
        glVertex3f(0.5f,  -0.5f,  0.5f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);       // Superior
        glVertex3f( -0.5f, 0.5f,  -0.5f);
        glVertex3f( 0.5f, 0.5f,  -0.5f);
        glVertex3f( 0.5f,  0.5f,  0.5f);
        glVertex3f(-0.5f,  0.5f,  0.5f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);       // Frontal
        glVertex3f( -0.5f, 0.5f,  0.5f);
        glVertex3f( 0.5f, 0.5f,  0.5f);
        glVertex3f( 0.5f,  -0.5f,  0.5f);
        glVertex3f(-0.5f,  -0.5f,  0.5f);
    glEnd();



}
