#ifndef LightManager_H
#define LightManager_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#ifdef _WIN32
#include <windows.h>
#endif
//#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include <vector>

class lights
{
public:
    GLfloat pos[4];
    GLfloat diffuse[4];
    GLfloat mat[4];
    GLfloat shin[];
    int active;
};


class LightManager
{
public:
    LightManager();
    ~LightManager();
    static LightManager* getInstance();
    void initLights();
    void addLight(int nlight);
    void enableLight(int nlight);
    void deleteLight(int nlight);
    void changePosition(int nLight, float x, float y, float z);
    void changeColor(int nLight, float r, float g, float b, float a);
    void showLight(int nLight);

    lights luces[7];
    int mode;
    int currentLight;

private:
        static LightManager* instance;
};

#endif // LightManager_H
