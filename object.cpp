#include "object.h"

Object::Object()
{
    id = 0;
    name = "default";
    sgZeroVec3(posicio);
    sgZeroVec3(escala);
    sgZeroVec4(rotacio);

    model = new CModel3DS("models/cub.3ds");
    model->CreateVBO(false);
}

Object::Object(int ident, std::string nom, sgVec3 pos, sgVec3 esc, sgQuat rot, std::string pathmodel)
{
    id = ident;
    name = nom;
    sgCopyVec3(posicio,pos);
    sgCopyVec3(escala,esc);
    sgCopyVec4(rotacio,rot);

    model = new CModel3DS(pathmodel);

    model->CreateVBO(false);
}

void Object::Draw()
{
    glPushMatrix();

    glLoadIdentity();
    glTranslatef(posicio[0],posicio[1],posicio[2]);
    glScalef(escala[0],escala[1],escala[2]);

    sgMat4 rotmat;
    sgQuatToMatrix(rotmat,rotacio);
    glMultMatrixf((GLfloat*)rotmat);

    model->Draw();

    glPopMatrix();
}
