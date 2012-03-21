#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

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

#include "coldet/src/coldet.h"

class CollisionManager
{
public:
    CollisionManager();
    ~CollisionManager();
    static CollisionManager* getInstance();
    bool TestCollision(float,float,float);


private:
        static CollisionManager* instance;
        CollisionModel3D* m_pCollObj;
        void AddTriangle(float[3], float[3], float[3]);
};

#endif // COLLISIONMANAGER_H
