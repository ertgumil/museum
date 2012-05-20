#include "object.h"

Object::Object()
{
    id = 0;
    name = "default";

    posicio = QVector3D(0,0,0);
    escala = QVector3D(0,0,0);
    rotacio = QQuaternion(1,0,0,0);

    pathmodel = "models/SalaXavi.obj";
    model = glmReadOBJ(pathmodel.c_str(), 0);
}

Object::Object(int ident, QString nom, QVector3D pos, QVector3D esc, QQuaternion rot, QString pathmod)
{
    id = ident;
    name = nom.toStdString();

    posicio = pos;
    escala = esc;
    rotacio = rot;

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
    glTranslatef(posicio.x(),posicio.y(),posicio.z());
    glScalef(escala.x(),escala.y(),escala.z());

    QMatrix4x4 rotmat;
    rotmat.rotate(rotacio);

    static GLfloat mat[16];
    const qreal *data = rotmat.constData();
    for (int index = 0; index < 16; ++index)
         mat[index] = data[index];
    glMultMatrixf(mat);

    glmDraw(model,GLM_FLAT | GLM_TEXTURE | GLM_MATERIAL);

    glPopMatrix();
}
