#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H

#include <lib3ds/file.h>
#include <lib3ds/camera.h>
#include <lib3ds/mesh.h>
#include <lib3ds/node.h>
#include <lib3ds/material.h>
#include <lib3ds/matrix.h>
#include <lib3ds/vector.h>
#include <lib3ds/light.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include <QGLPixelBuffer>
#include <QGLContext>

// Our 3DS model class
class CModel3DS
{
        public:
                CModel3DS(std:: string filename);
                virtual void Draw() const;
                virtual void CreateVBO();
                virtual ~CModel3DS();
        protected:
                void GetFaces();
                unsigned int m_TotalFaces;
                Lib3dsFile * m_model;
                GLuint m_VertexVBO, m_NormalVBO;
};

#endif // OBJECTLOADER_H

