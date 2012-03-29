#include "object.h"

Object::Object(int id, std::string nom, sgVec3 pos, sgVec3 esc, sgQuat rot, std::string model)
{

}

void Object::Draw()
{
    model->Draw();
}
