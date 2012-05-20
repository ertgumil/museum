#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H


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

#include "coldet/src/coldet.h"
#include <QtDebug>
#include <QVector3D>
#include <vector>
#include "sg/sg.h"

class CollisionManager
{
public:
    CollisionManager();
    ~CollisionManager();
    static CollisionManager* getInstance();
    bool TestCollisionSphere(float,float,float);
    void AddTriangle(float* vertex1, float* vertex2, float* vertex3);
    void FinalizeCollisionObject();
    bool TestCollisionRay(float* pointCol,float* origin,float *direction);
    float TestFloorRay(float* origin);

    void drawCollision();

private:
        static CollisionManager* instance;
        static CollisionModel3D* m_pCollObj;
        //void AddTriangle(float[3], float[3], float[3]);

        std::vector<QVector3D> vertexs;
};

#endif // COLLISIONMANAGER_H
