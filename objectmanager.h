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

    int count;

    void AddObject(Object* object);
    void AddObject(QString nom, sgVec3 pos, sgVec3 esc, sgQuat rot, QString model);
    void RemoveObject(int id);
    void RemoveAll();
    int getId();

    Object* GetObject(int id);
    Object* GetObject(std::string nom);

    std::vector<Object*>::iterator FirstObject();
    std::vector<Object*>::iterator LastObject();

    void ChangePos(int id, sgVec3 pos);

    void Draw();

private:
    static ObjectManager* instance;
    std::vector<Object*> objectes;

};

#endif // OBJECTMANAGER_H
