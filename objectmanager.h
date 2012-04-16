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
    void AddObject(std::string nom, sgVec3 pos, sgVec3 esc, sgQuat rot, std::string model);
    void RemoveObject(int id);
    void RemoveAll();

    Object* GetObject(int id);
    Object* GetObject(std::string nom);

    std::vector<Object*>::iterator FirstObject();
    std::vector<Object*>::iterator LastObject();

    void Draw();

private:
    static ObjectManager* instance;
    std::vector<Object*> objectes;

    unsigned int count;
};

#endif // OBJECTMANAGER_H
