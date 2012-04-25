#include "glwidgetmap.h"

glwidgetmap* glwidgetmap::instance = NULL;

glwidgetmap::glwidgetmap(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);
}

glwidgetmap::~glwidgetmap(){
    delete(instance);
}

glwidgetmap* glwidgetmap::getInstance() {
    if (!instance) {
        instance = new glwidgetmap();
    }
    return instance;
}

void glwidgetmap::initializeGL() {



}
void glwidgetmap::paintGL() {

}

void glwidgetmap::setPos(int x, int y){
    qDebug() << x << "," << y;
}


