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

class LightManager
{
public:
    LightManager();
    ~LightManager();
    static LightManager* getInstance();
<<<<<<< HEAD
    void addLight(int,float,float,float);
=======
    void addLight();
>>>>>>> 101356258ae3e4e9669d7e1cbd699a519b936ad7

private:
        static LightManager* instance;
};

#endif // LightManager_H
