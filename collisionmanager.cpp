#include "collisionmanager.h"

CollisionManager* CollisionManager::instance = NULL;

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

bool CollisionManager::TestCollision(float x, float y, float z)
{

   return false;
}

void CollisionManager::AddTriangle(float* pos1, float* pos2, float* pos3)
{
        m_pCollObj->addTriangle( pos1[0], pos1[1], pos1[2],
                             pos2[0], pos2[1], pos2[2],
                             pos3[0], pos3[1], pos3[2]);
}
