//Se encarga de la visualización del objeto.

#ifndef _GLWIDGET_H
#define _GLWIDGET_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include <QtOpenGL/QGLWidget>
#include <QGLShaderProgram>
#include "Model.h"
#include "Util.h"
#include "cameracontrol.h"
#include "lightmanager.h"
#include "objectmanager.h"
#include "xmlmanager.h"
#include "glwidgetmap.h"
#include "pointer.h"
#include "glm/glm.h"

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(QWidget *parent = NULL);

public slots:
    void SetBackgroundBlue();
    void SeveralViews();
    void OrthoView();
    void ProjView();
    void FullView();
    void LoadFiles();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void view4();
    void project(float,float,float); //escoge proyección

private:
    bool m_project; //TRUE: perspectiva, FALSE: ortho.
    bool m_viewer; //TRUE: Solo el objeto, FALSE: scyscor.

    bool isMoving; //TRUE: se esta manipulando la camara.
    bool isZoom;
    bool isMouseReleased;

    float m_R;
    float m_ull_x;
    float m_ull_y;
    float m_ull_z;

    float alphaCamera;
    float betaCamera;

    float xCamera;
    float yCamera;

    QGLShaderProgram m_shader;
    enum viewEnum { PROJEC, ORTHO, PLANTA, ALCAT, PERFIL, ISOMETRICA, FULL };

    GLMmodel* model;
};

#endif  /* _GLWIDGET_H */
