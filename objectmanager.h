#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include "object.h"

class ObjectManager
{
public:
    ObjectManager();
    ~ObjectManager();
    static ObjectManager* getInstance();

    void AddObject(Object* object);
    void RemoveObject(int id);

    Object* GetObject(int id);
    Object* GetObject(std::string name);

    void Draw();

private:
    static ObjectManager* instance;
    std::vector<Object*> objectes;

    unsigned int count;
};

#endif // OBJECTMANAGER_H
