#include "object.h"

Object::Object()
{
    id = 0;
    name = "default";
    sgZeroVec3(posicio);
    sgZeroVec3(escala);
    sgZeroVec4(rotacio);

    pathmodel = "models/SalaXavi.obj";
    model = glmReadOBJ(pathmodel.c_str(), 0);
}

Object::Object(int ident, QString nom, sgVec3 pos, sgVec3 esc, sgQuat rot, QString pathmod)
{
    id = ident;
    name = nom.toStdString();
    sgCopyVec3(posicio,pos);
    sgCopyVec3(escala,esc);
    sgCopyVec4(rotacio,rot);

    pathmodel = pathmod.toStdString();
    model = glmReadOBJ(pathmodel.c_str(), 0);
}

Object::~Object()
{
    delete model;
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

    glmDraw(model,GLM_FLAT | GLM_TEXTURE | GLM_MATERIAL);

    glPopMatrix();
}
