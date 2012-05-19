#ifndef POINTER_H
#define POINTER_H

#include "objectmanager.h"
#include "cameracontrol.h"
#include "collisionmanager.h"

class pointer
{
public:
    sgVec3 pos;

    pointer();
    ~pointer();
    static pointer* getInstance();
    void putObject(float x, float y);
    void changePos(float x, float y);
    void createObject(QString name, QString path);
    void calculPos(float x, float y);

private:
    static pointer* instance;
};

#endif // POINTER_H
