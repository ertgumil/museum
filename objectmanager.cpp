#include "objectmanager.h"

ObjectManager* ObjectManager::instance = NULL;
std::vector<Objecte> objectes = new std::vector<Objecte>();

ObjectManager::ObjectManager()
{
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
