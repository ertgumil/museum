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

void pointer::putObject(float x, float y)
{
    sgVec3 pos, esc;
    sgQuat rot;

    sgVec3 eyes,targets;

    float* eye = CameraControl::getInstance()->getEye();
    float* target = CameraControl::getInstance()->getTarget();
    float* cam = CameraControl::getInstance()->getCamConf();
    float near = *(cam+2);
    float dist = cos((*cam)*3.14/180)*near;
    sgVec3 dir;
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

    sgVec3 w,u;
    sgSetVec3(u,0.0f,0.0f,1.0f);


    w[0] = dir[1]*u[2] - dir[2]*u[1];
    w[1] = dir[0]*u[2] - dir[2]*u[0];
    w[2] = dir[0]*u[1] - dir[1]*u[0];


    sgVec3 P;

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


    sgVec3 pointCol;

    if(CollisionManager::getInstance()->TestCollisionRay(pointCol,eye,dir))
    {
        pos[0] = *pointCol;
        pos[1] = *(pointCol+1);
        pos[2] = * (pointCol+2);
        //CameraControl::getInstance()->setTarget(pos[0],pos[1],pos[2]);
    }
    else
    {
        pos[0] = *(eye)+dir[0]*(near+10);
        pos[1] = *(eye+1)+dir[1]*(near+10);
        pos[2] = *(eye+2)+dir[2]*(near+10);
    }


    sgSetVec3(esc,0.5,0.5,0.5); // Escala del nou objecte
    sgMakeIdentQuat(rot); // Rotacio del nou objecte

    if (ObjectManager::getInstance()->FirstObject().base() !=NULL)
    {

        ObjectManager::getInstance()->ChangePos(0,pos);
    }
    else
    {
        ObjectManager::getInstance()->AddObject("cub1",pos,esc,rot,"models/cub.3ds"); // Afegim l'objecte a l'escena
    }
}


