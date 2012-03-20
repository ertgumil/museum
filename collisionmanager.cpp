#include "collisionmanager.h"

CollisionManager* CollisionManager::instance = NULL;

CollisionManager::CollisionManager()
{
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
