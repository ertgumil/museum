#ifndef POINTER_H
#define POINTER_H

#include "objectmanager.h"
#include "cameracontrol.h"
#include "collisionmanager.h"

class pointer
{
public:
    pointer();
    ~pointer();
    static pointer* getInstance();
    void putObject(float x, float y);

private:
    static pointer* instance;
};

#endif // POINTER_H
