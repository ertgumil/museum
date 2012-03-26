#include "lightmanager.h"
#include "math.h"
#include "stdlib.h"

LightManager* LightManager::instance = NULL;

LightManager::LightManager()
{
}

LightManager::~LightManager()
{
    delete (instance);
}

LightManager* LightManager::getInstance()
{
    if (!instance) {
        instance = new LightManager();
    }
    return instance;
}


void LightManager::addLight(int nLlum,float x,float y,float z)
{

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };

    glShadeModel (GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    GLfloat pos[] = {x, y, z};
    GLfloat L0_Diffuse []={0.0f,0.0f,0.5f,1.0f};         //Luz roja
    GLfloat L1_Diffuse []={0.5f,0.0f,0.0f,1.0f};
    GLfloat L2_Diffuse []={0.0f,0.5f,0.0f,1.0f};
    GLfloat L3_Diffuse []={0.0f,0.5f,0.5f,1.0f};         //Luz roja
    GLfloat L4_Diffuse []={0.5f,0.5f,0.0f,1.0f};
    GLfloat L5_Diffuse []={0.5f,0.0f,0.5f,1.0f};
    switch (nLlum){
        case 0:     glEnable(GL_LIGHT0);
                    glLightfv(GL_LIGHT0, GL_POSITION, pos);
                    glLightfv(GL_LIGHT0, GL_DIFFUSE, L0_Diffuse);
                    break;
        case 1:     glEnable(GL_LIGHT1);
                    glLightfv(GL_LIGHT1, GL_POSITION, pos);
                    glLightfv(GL_LIGHT1, GL_DIFFUSE, L1_Diffuse);
                    break;
        case 2:     glEnable(GL_LIGHT2);
                    glLightfv(GL_LIGHT2, GL_POSITION, pos);
                    glLightfv(GL_LIGHT2, GL_DIFFUSE, L2_Diffuse);
                    break;
        case 3:     glEnable(GL_LIGHT3);
                    glLightfv(GL_LIGHT3, GL_POSITION, pos);
                     glLightfv(GL_LIGHT3, GL_DIFFUSE, L3_Diffuse);
                    break;
        case 4:     glEnable(GL_LIGHT4);
                    glLightfv(GL_LIGHT4, GL_POSITION, pos);
                     glLightfv(GL_LIGHT4, GL_DIFFUSE, L4_Diffuse);
                    break;
        case 5:     glEnable(GL_LIGHT5);
                    glLightfv(GL_LIGHT5, GL_POSITION, pos);
                     glLightfv(GL_LIGHT5, GL_DIFFUSE, L5_Diffuse);
                    break;
        case 6:     glEnable(GL_LIGHT6);
                    glLightfv(GL_LIGHT6, GL_POSITION, pos);
                    break;
        }

}
