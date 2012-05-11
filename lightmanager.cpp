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

void LightManager::enableLight(int nLight) //mostrar una llum
{
    float mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    float mat_shininess[] = { 50.0 };

    glShadeModel (GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);

    switch (nLight){
        case 0:     glEnable(GL_LIGHT0);
                    break;
        case 1:     glEnable(GL_LIGHT1);
                    break;
        case 2:     glEnable(GL_LIGHT2);
                    break;
        case 3:     glEnable(GL_LIGHT3);
                    break;
        case 4:     glEnable(GL_LIGHT4);
                    break;
        case 5:     glEnable(GL_LIGHT5);
                    break;
        case 6:     glEnable(GL_LIGHT6);
                    break;
    }
}
void LightManager::showLight(int nLight) //mostrar una llum
{
    switch (nLight){
        case 0:     glLightfv(GL_LIGHT0, GL_POSITION, luces[nLight].pos);
                    //glLightfv(GL_LIGHT0, GL_DIFFUSE, luces[nLight].diffuse);
                    break;
        case 1:     glLightfv(GL_LIGHT1, GL_POSITION, luces[nLight].pos);
                   // glLightfv(GL_LIGHT1, GL_DIFFUSE, luces[nLight].diffuse);
                    break;
        case 2:     glLightfv(GL_LIGHT2, GL_POSITION, luces[nLight].pos);
                   // glLightfv(GL_LIGHT2, GL_DIFFUSE, luces[nLight].diffuse);
                    break;
        case 3:     glLightfv(GL_LIGHT3, GL_POSITION, luces[nLight].pos);
                   // glLightfv(GL_LIGHT3, GL_DIFFUSE, luces[nLight].diffuse);
                    break;
        case 4:     glLightfv(GL_LIGHT4, GL_POSITION, luces[nLight].pos);
                   // glLightfv(GL_LIGHT4, GL_DIFFUSE, luces[nLight].diffuse);
                    break;
        case 5:     glLightfv(GL_LIGHT5, GL_POSITION, luces[nLight].pos);
                    //glLightfv(GL_LIGHT5, GL_DIFFUSE, luces[nLight].diffuse);
                    break;
        case 6:     glLightfv(GL_LIGHT6, GL_POSITION, luces[nLight].pos);
                    //glLightfv(GL_LIGHT6, GL_DIFFUSE, luces[nLight].diffuse);
                    break;
    }
}

void LightManager::addLight(int nLight) //afegir una nova llum
{
    if (luces[nLight].active!=1){
        luces[nLight].pos[0] = 100.0;
        luces[nLight].pos[1] = 100.0;
        luces[nLight].pos[2] = 100.0;

        luces[nLight].diffuse[0] = 0.0;
        luces[nLight].diffuse[1] = 0.5;
        luces[nLight].diffuse[2] = 0.0;
        luces[nLight].diffuse[3] = 1.0;

        enableLight(nLight);
        showLight(nLight);
        luces[nLight].active=1;
    }

}


void LightManager::deleteLight(int nLight)  //desactivar una llum
{
    switch(nLight)
    {
    case 0: glDisable(GL_LIGHT0);
        break;
    case 1: glDisable(GL_LIGHT1);
        break;
    case 2: glDisable(GL_LIGHT2);
        break;
    case 3: glDisable(GL_LIGHT3);
        break;
    case 4: glDisable(GL_LIGHT4);
        break;
    case 5: glDisable(GL_LIGHT5);
        break;
    case 6: glDisable(GL_LIGHT6);
        break;
    }
    luces[nLight].active=0;
}

void LightManager::changePosition(int nLight, float x, float y, float z)    //cambiar la posicio d'una llum
{
    luces[nLight].pos[0] = x;
    luces[nLight].pos[1] = y;
    luces[nLight].pos[2] = z;
    showLight(nLight);
}

void LightManager::changeColor(int nLight, float r, float g, float b, float a)  //cambiar el color d'una llum
{
    luces[nLight].diffuse[0] = r;
    luces[nLight].diffuse[1] = g;
    luces[nLight].diffuse[2] = b;
    luces[nLight].diffuse[3] = a;
    showLight(nLight);
}
