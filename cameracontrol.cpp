#include "cameracontrol.h"
#include "collisionmanager.h"
#include "math.h"
#include "waymanager.h"
#include "xmlruta.h"


CameraControl* CameraControl::instance = NULL;
float CameraControl::Target[3] = {0.0f,0.0f,0.0f};
float CameraControl::Eye[3]= {40.0f,0.0f,40.0f};
float CameraControl::Cam[4]= {30.0f,1.0f,1.0f,1000.0f};
float CameraControl::AngleCam = 1.0f;
float CameraControl::PitchCam = 1.0f;
float CameraControl::Zoom = 40.0f;
bool CameraControl::VisualMode = true;
bool CameraControl::onRoute=false;
float angleCamY = asin(30.0f/40.0f);

CameraControl::CameraControl()
{
}

CameraControl::~CameraControl(){
    delete(instance);
}


void CameraControl::RotateCam(float alpha,float beta){
    AngleCam= float(int(AngleCam+alpha)%360);
    PitchCam= float(int(PitchCam+beta)%180);

    float rads = AngleCam*3.14/180;
    if(VisualMode)
    {
        Eye[0] = Zoom*cos(rads);
        Eye[1] = Zoom*sin(rads);
    }
    else
    {
        float pitchs = PitchCam*3.14/180;
        Target[0] = Zoom*sin(rads)*cos(pitchs);
        Target[1] = Zoom*cos(rads)*cos(pitchs);
        Target[2] = -Zoom*sin(pitchs);
    }
}


void CameraControl::ChangeVisualMode(){
    VisualMode = !VisualMode;


    if(VisualMode){ ///Camara Grua
       Eye[0] = 40.0f;
       Eye[1] = 0.0f;
       Eye[2] = 30.0f;
       Target[0] = 0.0f;
       Target[1] = 0.0f;
       Target[2] = 0.0f;
       Zoom = 40.0f;

       Cam[0] = 30.0f;
       Cam[1]= Cam[1];
       Cam[2] = 1.0f;
       Cam[3] = Zoom + 4000.0f;
       AngleCam = 1.0f;
       angleCamY = asin(Eye[2]/Eye[0]);

    }
    else{ /// Camara FPS
       Eye[0] = -51.98f;
       Eye[1] = -1.34f;
       Eye[2] = -4.03f;
       Eye[2] = CollisionManager::getInstance()->TestFloorRay(Eye);
       Zoom = 50.0f;

       Target[0] = 49.92f;
       Target[1] = 0.91f;
       Target[2] = 2.61f;

       AngleCam = 1.0f;
       PitchCam = 1.0f;

       Cam[0] = 30.0f;
       Cam[1]= Cam[1];
       Cam[2] = 1.0f;
       Cam[3] = 5000.0f;

    }
}



void CameraControl::ConfigureCam(float angle, float aspect,float near, float far){
    Cam[0] = angle;
    Cam[1] = aspect;
    Cam[2] = near;
    Cam[3] = far;

}

void CameraControl::ConfigureAspect(float aspect){
    Cam[1] = aspect;
}

void CameraControl::DefineTarget(float x,float y ,float z ){
    CameraControl::Target[0] = x;
    CameraControl::Target[1] = y;
    CameraControl::Target[2] = z;
}


void CameraControl::DefineEye(float x, float y , float z){
    CameraControl::Eye[0] = x;
    CameraControl::Eye[1] = y;
    CameraControl::Eye[2] = z;
}



CameraControl* CameraControl::getInstance() {
    if (!instance) {
        instance = new CameraControl();
    }
    return instance;
}
void CameraControl::updateRoute()
{
    if(onRoute)
    {
        float oldEye[3] = {Eye[0],Eye[1],Eye[2]};
        QVector2D pos;
        pos.setX(Eye[0]);
        pos.setY(Eye[1]);
        QVector2D dir = WayManager::getInstance()->getDir(pos);
        Eye[0] += (float)dir.x();
        Eye[1] += (float)dir.y();
        Eye[2] = CollisionManager::getInstance()->TestFloorRay(Eye);
    }
}
void CameraControl::PutCam(){


    glMatrixMode(GL_PROJECTION);    //escollim treballar amb la matriu PROJECTION
    glLoadIdentity();               //netejar la matriu actual

    gluPerspective(Cam[0], Cam[1], Cam[2], Cam[3]);
    if (VisualMode)
        gluLookAt(Eye[0]+Target[0],Eye[1]+Target[1],Eye[2]+Target[2], Target[0], Target[1], Target[2], 0.0f, 0.0f, 1.0f);
    else
        if(onRoute)
        {
            gluLookAt(Eye[0],Eye[1],Eye[2], Eye[0]+Target[0], Eye[1]+Target[1], Eye[2]+Target[2], 0.0f, 0.0f, 1.0f);
        }
        else
            gluLookAt(Eye[0],Eye[1],Eye[2], Eye[0]+Target[0], Eye[1]+Target[1], Eye[2]+Target[2], 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glLoadIdentity();           //netejar la matriu actual


}

float* CameraControl::getEye(){
    return Eye;

}
float CameraControl::getEyex(){
    return  CameraControl::Eye[0] ;

}
float CameraControl::getEyey(){
    return  CameraControl::Eye[1] ;

}
float CameraControl::getEyez(){
    return  CameraControl::Eye[2] ;

}

float* CameraControl::getTarget(){
    return Target;

}

void CameraControl::RefreshTarget(float x,float y, float z){

    if(VisualMode){

       if(AngleCam>-45 && AngleCam<45){
            Target[0] += x;
            Target[1] += -y;
            Target[2] += z;
        }
       if(AngleCam>45 && AngleCam<135){
            Target[0] += y;
            Target[1] += x;
            Target[2] += z;
        }
        if(AngleCam>135 && AngleCam<225){
            Target[0] += -x;
            Target[1] += y;
            Target[2] += z;
        }
       if(AngleCam>225 && AngleCam<315){
            Target[0] += -y;
            Target[1] += -x;
            Target[2] += z;
        }
        if(AngleCam>-315 && AngleCam<-225){
            Target[0] += y;
            Target[1] += x;
            Target[2] += z;
        }

        if(AngleCam>-225 && AngleCam<-135){
            Target[0] += -x;
            Target[1] += y;
            Target[2] += z;
        }
        if(AngleCam>-135 && AngleCam<-45){
            Target[0] += -y;
            Target[1] += -x;
            Target[2] += z;
        }
    }
    else{
        float oldEye[3] = {Eye[0],Eye[1],Eye[2]};
        float rads = AngleCam*3.14/180;
        if (x > 0) {
            //va hacia atras
            Eye[1] -= cos(rads);
            Eye[0] -= sin(rads);
            Eye[2] = CollisionManager::getInstance()->TestFloorRay(Eye);
        }
        else if (x < 0) {
            //Solo va hacia adelante
            Eye[1] += cos(rads);
            Eye[0] += sin(rads);
            Eye[2] = CollisionManager::getInstance()->TestFloorRay(Eye);
        }
        if (y > 0) {
            //va hacia la derecha
            Eye[1] += sin(rads);
            Eye[0] -= cos(rads);
            Eye[2] = CollisionManager::getInstance()->TestFloorRay(Eye);
        }
        else if(y < 0) {
            //va hacia la izquierda
            Eye[1] -= sin(rads);
            Eye[0] += cos(rads);
            Eye[2] = CollisionManager::getInstance()->TestFloorRay(Eye);
        }
        if (z > 0) {
            //Eye[2] += 0.1;
            //AngleCam+=1;
            Target[2] += sin(rads);
        }
        else if (z < 0) {
            //Eye[2] -= 0.1;
            //AngleCam-=1;
            Target[2] -= sin(rads);
        }
        if(CollisionManager::getInstance()->TestCollisionSphere(Eye[0],Eye[1],Eye[2])){ Eye[0] = oldEye[0]; Eye[1]=oldEye[1]; Eye[2] = oldEye[2];}

    }


}


void CameraControl::RefreshZoom(float zoom){
    if(VisualMode)
    {
        Zoom += zoom;
        if (Zoom < 3.0f) Zoom = 3.0f;
        else Cam[3]+=zoom;

        float rads = AngleCam*3.14/180;


        Eye[0] = Zoom*cos(rads);
        Eye[1] = Zoom*sin(rads);
        Eye[2] = Zoom*sin(angleCamY);
    }

}

float* CameraControl::getCamConf()
{
    return Cam;
}

void CameraControl::setTarget(float x,float y,float z)
{
    Target[0] = x;
    Target[1] = y;
    Target[2] = z;

}
bool CameraControl::isSimsCam()
{
    return VisualMode;
}
void CameraControl::StartRoute()
{
    onRoute = true;
    QVector2D point = WayManager::getInstance()->getStartPoint();
    Eye[0] = point.x();
    Eye[1] = point.y();
    Eye[2] = CollisionManager::getInstance()->TestFloorRay(Eye);


}
void CameraControl::StopRoute()
{
    onRoute = false;
}

float CameraControl::getAngleCam()
{
    return AngleCam;
}
