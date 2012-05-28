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
void pointer::calcul2(float x, float y)
{
    float eyes[3],targets[3];

    float* eye = CameraControl::getInstance()->getEye();
    float* target = CameraControl::getInstance()->getTarget();
    float* cam = CameraControl::getInstance()->getCamConf();
    float near = *(cam+2);
    float dist = cos((*cam)*3.14/180)*near*10;

    float dir[3];
    eyes[0]= *eye;
    eyes[1]= *(eye+1);
    eyes[2]= *(eye+2);
    targets[0]= *target;
    targets[1]= *(target+1);
    targets[2]= *(target+2);

    dir[0] = (*target);
    dir[1] = (*(target+1));
    float a = std::max(fabs(dir[0]),fabs(dir[1]));
    dir[2] = (*(target+2));
    a = std::max((float)fabs(dir[2]),a);


    dir[0] =(dir[0]/a);
    dir[1] =(dir[1]/a);
    dir[2] =(dir[2]/a);

    float rads = CameraControl::getInstance()->getAngleCam()*3.14/180;

    float pointCol[3];

    if(CollisionManager::getInstance()->TestCollisionRay(pointCol,eye,dir))
    {
        pos = QVector3D(*pointCol-x*cos(rads)*dist,*(pointCol+1)+x*sin(rads)*dist,*(pointCol+2)+y*dist);
        //CameraControl::getInstance()->setTarget(pos[0],pos[1],pos[2]);
    }
    else
    {
        pos = QVector3D(*(eye)+dir[0]*(near+10), *(eye+1)+dir[1]*(near+10),*(eye+2)+dir[2]*(near+10));
    }

}

void pointer::calcul(float x, float y)
{
    float eyes[3],targets[3];

    float* eye = CameraControl::getInstance()->getEye();
    float* target = CameraControl::getInstance()->getTarget();
    float* cam = CameraControl::getInstance()->getCamConf();
    float near = *(cam+2);
    float dist = cos((*cam)*3.14/180)*near*10;
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


    float pointCol[3];
    float AngleCam = CameraControl::getInstance()->getAngleCam();

    if(AngleCam>-45 && AngleCam<45){
         x = -x;
         y = -y;
     }
    if(AngleCam>45 && AngleCam<135){
        float c = x;
         x= -y;
         y= c;
     }

     if(AngleCam>135 && AngleCam<225){
         x = x;
         y = -y;
     }

    if(AngleCam>225 && AngleCam<315){
         float c = y;
         y = -x;
         x = c;

     }

    if(AngleCam>-315 && AngleCam<-225){
          float c = y;
          y = x;
          x = -c;

     }


     if(AngleCam>-225 && AngleCam<-135){
         x = x;
         y = y;
     }

     if(AngleCam>-135 && AngleCam<-45){
           float c = y;
           y = -x;
           x = c;
     }

    if(CollisionManager::getInstance()->TestCollisionRay(pointCol,eye,dir))
    {
        pos = QVector3D(*pointCol+y*dist,*(pointCol+1)+x*dist,targets[2]+1);
        //CameraControl::getInstance()->setTarget(pos[0],pos[1],pos[2]);
    }
    else
    {
        pos = QVector3D(*(eye)+dir[0]*(near+10), *(eye+1)+dir[1]*(near+10),*(eye+2)+dir[2]*(near+10));
    }
}

void pointer::changePos(float x, float y, int id) {

    int mode = LightManager::getInstance()->mode;

    qDebug()<<pos;

    if(visitant!=1){
        if(CameraControl::getInstance()->isSimsCam())
            calcul(x,y);
        else
            calcul2(x,y);

        if(ObjectManager::getInstance()->getId() > 0 && mode == 0)
            ObjectManager::getInstance()->GetObject(id)->posicio = pos;

        int lol = LightManager::getInstance()->currentLight;

        if(mode == 1 && LightManager::getInstance()->currentLight != 0)
            LightManager::getInstance()->changePosition(LightManager::getInstance()->currentLight,pos.x(),pos.y(),pos.z());
    }
}

void pointer::visitantOn(){
    visitant=1;
}


