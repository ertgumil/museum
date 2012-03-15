#include "cameracontrol.h"
#include "math.h"


CameraControl* CameraControl::instance = NULL;
float CameraControl::Target[3] = {0.0f,0.0f,0.0f};
float CameraControl::Eye[3]= {40.0f,0.0f,30.0f};
float CameraControl::Cam[4]= {30.0f,1.0f,0.1f,100.0f};
float CameraControl::AngleCam = 1.0f;
float CameraControl::Pitch = 1.0f;
float CameraControl::Zoom = 40.0f;
bool CameraControl::VisualMode = true;
float angleCamY = asin(30.0f/40.0f);

CameraControl::CameraControl()
{
}

CameraControl::~CameraControl(){
    delete(instance);
}


void CameraControl::ViewCam(float alpha,float beta){
    AngleCam= float(int(AngleCam+alpha)%360);

    float rads = AngleCam*3.14/180;

    Zoom = 10;

    Target[0] = Zoom*cos(rads);
    Target[2] = Zoom*sin(rads);

   /* Pitch= float(Pitch+alpha);

    rads = Pitch*3.14/180;


    Target[1] = Zoom*cos(rads);
*/

}

void CameraControl::RotateCam(float alpha){
    if(VisualMode)
    {

        AngleCam= float(int(AngleCam+alpha)%360);

        float rads = AngleCam*3.14/180;


        Eye[0] = Zoom*cos(rads);
        Eye[1] = Zoom*sin(rads);
    }
    else
    {
        AngleCam= float(int(AngleCam+alpha)%360);

        float rads = AngleCam*3.14/180;


        Target[0] = Zoom*cos(rads);
        Target[1] = Zoom*sin(rads);
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
       Cam[2] = 0.1f;
       Cam[3] = Zoom + 40.0f;
       AngleCam = 1.0f;
       angleCamY = asin(Eye[2]/Eye[1]);

    }
    else{ /// Camara FPS
       Eye[0] = 0.0f;
       Eye[1] = -6.0f;
       Eye[2] = 1.0f;

       Zoom = 5.0f;

       Target[0] = 5.0f;
       Target[1] = 0.0f;
       Target[2] = 0.0f;

       AngleCam = 1.0f;

       Cam[0] = 30.0f;
       Cam[1]= Cam[1];
       Cam[2] = 0.1f;
       Cam[3] = 50.0f;
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

void CameraControl::PutCam(){


    glMatrixMode(GL_PROJECTION);    //escollim treballar amb la matriu PROJECTION
    glLoadIdentity();               //netejar la matriu actual

    gluPerspective(Cam[0], Cam[1], Cam[2], Cam[3]);
    if (VisualMode)
        gluLookAt(Eye[0]+Target[0],Eye[1]+Target[1],Eye[2]+Target[2], Target[0], Target[1], Target[2], 0.0f, 0.0f, 1.0f);
    else
        gluLookAt(Eye[0],Eye[1],Eye[2], Eye[0]+Target[0], Eye[1]+Target[1], Eye[2]+Target[2], 0.0f, 0.0f, 1.0f);


    glMatrixMode(GL_MODELVIEW); //escollim treballar amb la matriu MODELVIEW
    glLoadIdentity();           //netejar la matriu actual


}

float* CameraControl::getEye(){
    return Eye;

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
            Target[1] += x;
            Target[2] += z;
        }
    }
    else{
       // Eye[0] += -x;
       // Eye[1] += -y;
       // Eye[2] += z;
        float rads = AngleCam*3.14/180;

        /*
        //Solo va hacia adelante
        Eye[0] += cos(rads);
        Eye[1] += sin(rads);
        Eye[2] = Eye[2];
        */

        if (x > 0) {
            //va hacia atras
            Eye[0] -= cos(rads);
            Eye[1] -= sin(rads);
            Eye[2] = Eye[2];
        }
        else if (x < 0) {
            //Solo va hacia adelante
            Eye[0] += cos(rads);
            Eye[1] += sin(rads);
            Eye[2] = Eye[2];
        }
        if (y > 0) {
            //va hacia la derecha
            Eye[0] -= sin(rads);
            Eye[1] -= cos(rads);
            Eye[2] = Eye[2];
        }
        else if(y < 0) {
            //va hacia la izquierda
            Eye[0] += sin(rads);
            Eye[1] += cos(rads);
            Eye[2] = Eye[2];
        }
        if (z > 0) {
            Eye[2] += 0.1;
        }
        else if (z < 0) {
            Eye[2] -= 0.1;
        }
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
