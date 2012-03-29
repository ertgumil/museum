#include "objectmanager.h"

ObjectManager* ObjectManager::instance = NULL;

ObjectManager::ObjectManager()
{
    count = 0;
}

ObjectManager::~ObjectManager()
{
}

ObjectManager* ObjectManager::getInstance()
{
    if (!instance) {
        instance = new ObjectManager();
    }
    return instance;
}

void ObjectManager::Draw()
{
    std::vector<Object*>::iterator iter;

    for (iter = objectes.begin(); iter != objectes.end(); ++iter)
    {
        (*iter)->Draw();
    }
}
