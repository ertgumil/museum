#include "lightmanager.h"

LightManager* LightManager::instance = NULL;

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


void LightManager::addLight()
{

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    GLfloat pos[] = {300.0, 300.0, 300.0};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
}
