#ifndef OBJECT_H
#define OBJECT_H

#include "sg/sg.h"
#include "objectloader.h"

#include <string>

class Object
{
public:
    Object(int id, std::string nom, sgVec3 pos, sgVec3 esc, sgQuat rot, std::string model);

    void Draw();

    sgVec3 posicio;
    sgVec3 escala;
    sgQuat rotacio;

    sgBox boundingBox;

    int id;
    std::string name;

    CModel3DS* model;
};

#endif // OBJECT_H