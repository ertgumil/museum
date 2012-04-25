#ifndef _GLWIDGETMAP_H
#define _GLWIDGETMAP_H

#include <QtOpenGL/QGLWidget>
#include <QGLShaderProgram>
#include "Model.h"
#include "Util.h"
#include "cameracontrol.h"


class glwidgetmap : public QGLWidget {

public:
    glwidgetmap(QWidget *parent = NULL);
    ~glwidgetmap();
    static glwidgetmap* getInstance();
    void setPos(int x, int y);

protected:
    void initializeGL();
    void paintGL();


private:
    //static float Target[3];
    static glwidgetmap* instance;
};

#endif  /* _GLWIDGET_H */
