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
    bool TestCollisionSphere(float,float,float);
    void AddTriangle(float* vertex1, float* vertex2, float* vertex3);
    void FinalizeCollisionObject();

private:
        static CollisionManager* instance;
        static CollisionModel3D* m_pCollObj;
        //void AddTriangle(float[3], float[3], float[3]);
};

#endif // COLLISIONMANAGER_H
