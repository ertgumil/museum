#include "waymanager.h"



WayManager* WayManager::instance = NULL;

WayManager::WayManager()
{
    m_vel = 20;
    stop = false;
    m_currentIndex = 0;

}


WayManager* WayManager::getInstance() {

    if (!instance) {
        instance = new WayManager();
    }
    return instance;

}

QVector2D WayManager::getDir(QVector2D currentPos)
{
     QVector2D dir = coord[m_currentIndex] - currentPos;

    float max = std::max(fabs(dir.x()),fabs(dir.y()));
    if (dir.x()*dir.x() + dir.y()*dir.y()<0.2)
    {
        if (m_currentIndex == coord.size()-1)
        {
            dir.setX(0);
            dir.setY(0);
            return dir;
        }
        else
        {
            m_currentIndex ++;
        }
    }
    if (max>0) dir/=max;
    double tim = m_timer.restart() +0.001;
    float desp = m_vel/tim + 0.01;
    dir*= desp;

    return dir;
}

QVector2D WayManager::getStartPoint()
{
    m_currentIndex = 1;
    m_timer.start();
    return coord[0];
}

void WayManager::addwayPoint(float x, float y)
{
    QVector2D a = QVector2D(x,y);
    coord.push_back(a);

}
void WayManager::pause()
{
    stop=!stop;
}
