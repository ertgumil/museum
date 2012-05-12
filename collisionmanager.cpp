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
        m_pCollObj->addTriangle( pos1[0], pos1[1], pos1[2],
                             pos2[0], pos2[1], pos2[2],
                             pos3[0], pos3[1], pos3[2]);
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
        return dir[2]+5.0f;
    }
    return *(origin+2);
}
