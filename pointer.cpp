#include "pointer.h"



pointer* pointer::instance = NULL;

pointer::pointer()
{
}

pointer* pointer::getInstance()
{
    if (!instance) {
        instance = new pointer();
    }
    return instance;
}

void pointer::calculPos(float x, float y)
{
    float eyes[3],targets[3];

    float* eye = CameraControl::getInstance()->getEye();
    float* target = CameraControl::getInstance()->getTarget();
    float* cam = CameraControl::getInstance()->getCamConf();
    float near = *(cam+2);
    float dist = cos((*cam)*3.14/180)*near;
    float dir[3];
    eyes[0]= *eye;
    eyes[1]= *(eye+1);
    eyes[2]= *(eye+2);
    targets[0]= *target;
    targets[1]= *(target+1);
    targets[2]= *(target+2);

    dir[0] = (*target-*eye);
    dir[1] = (*(target+1)-*(eye+1));
    float a = std::max(fabs(dir[0]),fabs(dir[1]));
    dir[2] = (*(target+2)-*(eye+2));
    a = std::max((float)fabs(dir[2]),a);

    dir[0] =(dir[0]/a);
    dir[1] =(dir[1]/a);
    dir[2] =(dir[2]/a);

    float w[3],u[3];
    u[0] = 0.0f;
    u[1] = 0.0f;
    u[2] = 1.0f;

    w[0] = dir[1]*u[2] - dir[2]*u[1];
    w[1] = dir[0]*u[2] - dir[2]*u[0];
    w[2] = dir[0]*u[1] - dir[1]*u[0];

    float P[3];

    P[0] = *(eye)+dir[0]*near + dist*y*u[0] + dist*x*w[0];
    P[1] = *(eye+1)+dir[1]*near + dist*y*u[1] + dist*x*w[1];
    P[2] = *(eye+2)+dir[2]*near + dist*y*u[2] + dist*x*w[2];

    dir[0] = (P[0]-*eye);
    dir[1] = (P[1]-*(eye+1));
    a = std::max(fabs(dir[0]),fabs(dir[1]));
    dir[2] = (P[2]-*(eye+2));
    a = std::max((float)fabs(dir[2]),a);

    dir[0] =(dir[0]/a);
    dir[1] =(dir[1]/a);
    dir[2] =(dir[2]/a);

    float pointCol[3];

    if(CollisionManager::getInstance()->TestCollisionRay(pointCol,eye,dir))
    {
        pos = QVector3D(*pointCol,*(pointCol+1),*(pointCol+2));
        //CameraControl::getInstance()->setTarget(pos[0],pos[1],pos[2]);
    }
    else
    {
        pos = QVector3D(*(eye)+dir[0]*(near+10), *(eye+1)+dir[1]*(near+10),*(eye+2)+dir[2]*(near+10));
    }
}

void pointer::changePos(float x, float y) {
    calculPos(x,y);
    ObjectManager::getInstance()->ChangePos(ObjectManager::getInstance()->getId()-1,pos);
}


