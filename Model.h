#ifndef _MODEL_H
#define _MODEL_H

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

class Model
{
public:
	Model();
	~Model();
        void Dibuixa();
        void DibuixaCub();
        void DibuixaEixos();
        void DibuixaTriangle();
        void Torna_Desp(float*); //Torna el desplaçament (x,y,z) del model respecte el centre del mon.
        void BoundingBox(float*);//Torna les coordenades de la caixa mínima del model (xmin,ymin,zmin,xmax,ymax,zmax)
        static Model* getInstance();


private:
        static Model* instance;

};
#endif /* _MODEL_H */
