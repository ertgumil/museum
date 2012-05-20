#include "collisionmanager.h"

CollisionManager* CollisionManager::instance = NULL;
CollisionModel3D* CollisionManager::m_pCollObj = NULL;

CollisionManager::CollisionManager()
{
   m_pCollObj = newCollisionModel3D( true );
}

CollisionManager::~CollisionManager()
{
    delete (instance);
}

CollisionManager* CollisionManager::getInstance()
{
    if (!instance) {
        instance = new CollisionManager();
    }
    return instance;
}

bool CollisionManager::TestCollisionSphere(float x, float y, float z)
{
   float origin[3] = {x,y,z};
   if (m_pCollObj->sphereCollision(origin,1))
        return true;
   return false;
}

void CollisionManager::AddTriangle(float* pos1, float* pos2, float* pos3)
{
        m_pCollObj->addTriangle( pos1[0], pos1[1], pos1[1],
                             pos2[0], pos2[1], pos2[1],
                             pos3[0], pos3[1], pos3[1]);

        QVector3D vpos1 = QVector3D(pos1[0], pos1[1], pos1[1]);
        QVector3D vpos2 = QVector3D(pos2[0], pos2[1], pos2[1]);
        QVector3D vpos3 = QVector3D(pos3[0], pos3[1], pos3[1]);

        vertexs.push_back(vpos1);
        vertexs.push_back(vpos2);
        vertexs.push_back(vpos3);
}

void CollisionManager::drawCollision()
{
    glPushMatrix();

    int i = 0;

    glDisable(GL_LIGHTING);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);

    for (i = 0; i<vertexs.size(); i++)
    {
        glVertex3f(vertexs[i].x(),vertexs[i].y(), vertexs[i].z());
    }

    glEnd();

    glEnable(GL_LIGHTING);

    glPopMatrix();
}

void CollisionManager::FinalizeCollisionObject()
{
    m_pCollObj->finalize();
}

bool CollisionManager::TestCollisionRay(float* pointCol,float* origin,float *direction)
{
    float near = 0;
    float far = 100;
    if (m_pCollObj->rayCollision(origin,direction,near,true,far))
    {
        m_pCollObj->getCollisionPoint(pointCol,true);
        return true;
    }
    return false;
}

float CollisionManager::TestFloorRay(float* origin)
{
    float dir[3] = {0.0f,0.0f,-1.0f};
    if (m_pCollObj->rayCollision(origin,dir,true,0.0f,50.0f))
    {
        m_pCollObj->getCollisionPoint(dir,true);
        qDebug() << "altura: " << dir[2]+5.0f;
        return dir[2]+5.0f;
    }
    return *(origin+2);
}
