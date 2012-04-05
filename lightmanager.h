#ifndef LightManager_H
#define LightManager_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include <lights.h>
#include <vector>

class LightManager
{
public:
    LightManager();
    ~LightManager();
    static LightManager* getInstance();
    void initLights();
    void addLight(int nlight);
    void addLight();
    void deleteLight(int nlight);
    void changePosition(int nLight, float x, float y, float z);
    void changeColor(int nLight, float r, float g, float b, float a);
    void showLight(int nLight);

    lights luces[7];

private:
        static LightManager* instance;
};

#endif // LightManager_H
