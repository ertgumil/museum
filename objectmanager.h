#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>

class ObjectManager
{
public:
    ObjectManager();
    ~ObjectManager();
    static ObjectManager* getInstance();
private:
    static ObjectManager* instance;
    std::vector<Object> objectes;
};

#endif // OBJECTMANAGER_H
