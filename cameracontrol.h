//Implementa el control de la camara.

#ifndef CAMERACONTROL_H
#define CAMERACONTROL_H

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

class CameraControl
{
public:
    CameraControl();
    ~CameraControl();
    static CameraControl* getInstance();

    void PutCam();
    void ChangeVisualMode(); //Cambia de camara primera persona a camara grua.
    void MoveCam(int dir); //Mueve la camara en la dirección indicada dependiendo del modo de camara.
    /////INIT METHODS/////
    void DefineTarget(float,float,float);
    void DefineEye(float, float, float);
    void ConfigureCam(float,float,float,float);
    void ConfigureAspect(float);

    ////Work Methods///
    float* getEye();
    float* getTarget();
    void RefreshTarget(float,float,float);
    void RefreshZoom(float);
    void RotateCam(float);
    void ViewCam(float,float);



private:
        static CameraControl* instance;
        static float Target[3];
        static float Eye[3];
        static float Cam[4];
        static float AngleCam;
        static float Pitch;
        static float Zoom;
        static bool VisualMode;
};

#endif // CAMERACONTROL_H
