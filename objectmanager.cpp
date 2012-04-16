#include "objectmanager.h"

ObjectManager* ObjectManager::instance = NULL;

ObjectManager::ObjectManager()
{
    count = 0;
}

ObjectManager::~ObjectManager()
{
    objectes.clear();
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

void ObjectManager::AddObject(Object* nou)
{
    count++;
    nou->id = count;
    objectes.push_back(nou);
}

void ObjectManager::AddObject(std::string nom, sgVec3 pos, sgVec3 esc, sgQuat rot, std::string model)
{
    Object* nou = new Object(count,nom,pos,esc,rot,model);

    AddObject(nou);
}

void ObjectManager::RemoveObject(int id)
{
    std::vector<Object*>::iterator iter;
    Object *trobat = NULL;
    int pos = 0;

    for (iter = objectes.begin(); iter != objectes.end() && trobat == NULL; ++iter)
    {
        if ( (*iter)->id == id )
            trobat = (*iter);
        else
            pos++;
    }

    if (trobat != NULL)
    {
        objectes.erase(objectes.begin()+pos);
        delete trobat;

        trobat = NULL;
    }
}

void ObjectManager::RemoveAll()
{
    objectes.clear();
}

Object* ObjectManager::GetObject(int id)
{
    std::vector<Object*>::iterator iter;
    Object *trobat = NULL;

    for (iter = objectes.begin(); iter != objectes.end() && trobat == NULL; ++iter)
    {
        if ( (*iter)->id == id )
            trobat = (*iter);
    }

    return trobat;
}

Object* ObjectManager::GetObject(std::string nom)
{
    std::vector<Object*>::iterator iter;
    Object *trobat = NULL;

    for (iter = objectes.begin(); iter != objectes.end() && trobat == NULL; ++iter)
    {
        if ( nom.compare((*iter)->name) == 0)
            trobat = (*iter);
    }

    return trobat;
}

std::vector<Object*>::iterator ObjectManager::FirstObject()
{
    return objectes.begin();
}

std::vector<Object*>::iterator ObjectManager::LastObject()
{
    return objectes.end();
}
