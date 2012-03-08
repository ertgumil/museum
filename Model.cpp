#include "Model.h"

Model* Model::instance = NULL;

float mida = 0.5f; //////tamany de la figura

Model::Model(){

}

Model::~Model(){
	
}

Model* Model::getInstance() {
    if (!instance) {
        instance = new Model();
    }
    return instance;
}

void Model::Dibuixa(){
	
}

void Model::DibuixaEixos() {

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(10.0f, 0.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINE);
        glVertex3f(0.0f, -0.0f, 0.0f);
        glVertex3f(0.0f, 10.0f, 0.0f);
    glEnd();
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 10.0f);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);

}
void Model::Torna_Desp(float * p){ //Torna el desplaçament (x,y,z) del model respecte el centre del mon.
    float desp[3] = {0.0f,0.0f,0.0f};
    *p = desp[0];
    p++;
    *p = desp[1];
    p++;
    *p = desp[2];
}
void Model::BoundingBox(float * bb){//Torna les coordenades de la caixa mínima del model (xmin,ymin,zmin,xmax,ymax,zmax.
    float BoundingBox[6] = {-mida,-mida,-mida,mida,mida,mida};
    *bb = BoundingBox[0];
    bb++;
    *bb = BoundingBox[1];
    bb++;
    *bb = BoundingBox[2];
    bb++;
    *bb = BoundingBox[3];
    bb++;
    *bb = BoundingBox[4];
    bb++;
    *bb = BoundingBox[2];

}
void Model::DibuixaCub() {
    glBegin(GL_QUADS);

        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(-mida,-mida, mida);
        glVertex3f( mida,-mida, mida);
        glVertex3f( mida,-mida,-mida);
        glVertex3f(-mida,-mida,-mida);

    //glEnd();
    //glBegin(GL_QUADS);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(-mida,mida,-mida);
        glVertex3f(-mida, mida, mida);
        glVertex3f(-mida,-mida, mida);
        glVertex3f(-mida,-mida,-mida);

    //glEnd();
    //glBegin(GL_QUADS);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f( mida,-mida,-mida);
        glVertex3f( mida, mida,-mida);
        glVertex3f(-mida, mida,-mida);
        glVertex3f(-mida,-mida,-mida);

    //glEnd();
    //glBegin(GL_QUADS);

        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f( mida, mida, mida);
        glVertex3f( mida, mida,-mida);
        glVertex3f( mida,-mida,-mida);
        glVertex3f( mida,-mida, mida);

    //glEnd();
    //glBegin(GL_QUADS);

        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f( mida, mida, mida);
        glVertex3f( mida,-mida, mida);
        glVertex3f(-mida,-mida, mida);
        glVertex3f(-mida, mida, mida);

    //glEnd();
    //glBegin(GL_QUADS);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-mida, mida, mida);
        glVertex3f(-mida, mida,-mida);
        glVertex3f( mida, mida,-mida);
        glVertex3f( mida, mida, mida);

    glEnd();

}
