#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include "object.h"
#include <QtGui>

class ObjectManager
{
public:
    ObjectManager();
    ~ObjectManager();
    static ObjectManager* getInstance();

    int count;

    void AddObject(Object* object);
    void AddObject(QString nom, QVector3D pos, QVector3D esc, QQuaternion rot, QString model);
    void RemoveObject(int id);
    void RemoveAll();
    int getId();

    Object* GetObject(int id);
    Object* GetObject(std::string nom);

    std::vector<Object*>::iterator FirstObject();
    std::vector<Object*>::iterator LastObject();

    void ChangePos(int id, QVector3D pos);

    void Draw();

private:
    static ObjectManager* instance;
    std::vector<Object*> objectes;

};

#endif // OBJECTMANAGER_H
