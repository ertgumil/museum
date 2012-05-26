#ifndef WAYMANAGER_H
#define WAYMANAGER_H


#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <vector>
#include <QtGui>

class WayManager
{

public:
    WayManager();
    ~WayManager();
    static WayManager* getInstance();
    QVector2D getDir(QVector2D currpos);
    QVector2D getStartPoint();
    void addwayPoint(float x, float y);
    void pause();
    void reset();

private:
    static WayManager* instance;
    QList<QVector2D> coord;
    int m_currentIndex;
    float m_vel;
    bool stop;
    QTime m_timer;

};

#endif // WAYMANAGER_H
