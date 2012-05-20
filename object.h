#ifndef OBJECT_H
#define OBJECT_H

#include "glm/glm.h"
#include <QString>
#include <QtGui>

#include <string>

class Object
{
public:
    Object();
    Object(int id, QString nom, QVector3D pos, QVector3D esc, QQuaternion rot, QString model);
    ~Object();

    void Draw();

    QVector3D posicio;
    QVector3D escala;
    QQuaternion rotacio;

    //sgBox boundingBox;

    int id;
    std::string name;
    std::string pathmodel;

    GLMmodel* model;
};

#endif // OBJECT_H
