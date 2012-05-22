#ifndef POINTER_H
#define POINTER_H

#include "objectmanager.h"
#include "cameracontrol.h"
#include "collisionmanager.h"
#include <QtGui>

class pointer
{
public:
    QVector3D pos;

    pointer();
    ~pointer();
    static pointer* getInstance();
    void putObject(float x, float y);
    void changePos(float x, float y, int id);
    void calculPos(float x, float y);

private:
    static pointer* instance;
};

#endif // POINTER_H
