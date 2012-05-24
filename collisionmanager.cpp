#include "collisionmanager.h"

CollisionManager* CollisionManager::instance = NULL;
CollisionModel3D* CollisionManager::m_pCollObj = NULL;

CollisionManager::CollisionManager()
{
   m_pCollObj = newCollisionModel3D( true );
}

CollisionManager::~CollisionManager()
{
    delete (instance);
}

CollisionManager* CollisionManager::getInstance()
{
    if (!instance) {
        instance = new CollisionManager();
    }
    return instance;
}

bool CollisionManager::TestCollisionSphere(float x, float y, float z)
{
   float origin[3] = {x,y,z};
   if (m_pCollObj->sphereCollision(origin,1))
        return true;
   return false;
}

void CollisionManager::AddTriangle(float* pos1, float* pos2, float* pos3)
{
        m_pCollObj->addTriangle( pos1[0], pos1[1], pos1[2],
                             pos2[0], pos2[1], pos2[2],
                             pos3[0], pos3[1], pos3[2]);

        QVector3D vpos1 = QVector3D(pos1[0], pos1[1], pos1[2]);
        QVector3D vpos2 = QVector3D(pos2[0], pos2[1], pos2[2]);
        QVector3D vpos3 = QVector3D(pos3[0], pos3[1], pos3[2]);

        vertexs.push_back(vpos1);
        vertexs.push_back(vpos2);
        vertexs.push_back(vpos3);

        //Obtenim els valors de caixa mínima
        xmin = xmin > pos1[0] ? pos1[0] : xmin;
        //qDebug() << "xmin" << xmin ;
        xmax = xmax < pos1[0] ? pos1[0] : xmax;
        //qDebug() << "xmax" << xmax ;

        ymin = ymin > pos2[0] ? pos2[0] : ymin;
        //qDebug() << "ymin" << ymin ;
        ymax = ymax < pos2[0] ? pos2[0] : ymax;
        //qDebug() << "ymax" << ymax ;

        zmin = zmin > pos3[0] ? pos3[0] : zmin;
        //qDebug() << "zmin" << zmin ;
        zmax = zmax < pos3[0] ? pos3[0] : zmax;
        //qDebug() << "zmax" << zmax ;

}

void CollisionManager::drawCollision()
{
    glPushMatrix();

    int i = 0;

    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    glDisable(GL_LIGHTING);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);

    for (i = 0; i<vertexs.size(); i++)
    {
        glVertex3f(vertexs[i].x(),vertexs[i].y(), vertexs[i].z());
    }

    glEnd();

    glEnable(GL_LIGHTING);
    glPolygonMode( GL_FRONT, GL_FILL );

    glPopMatrix();
}

void CollisionManager::FinalizeCollisionObject()
{
    m_pCollObj->finalize();
}

bool CollisionManager::TestCollisionRay(float* pointCol,float* origin,float *direction)
{
    float near = 0;
    float far = 1000;
    if (m_pCollObj->rayCollision(origin,direction,near,true,far))
    {
        m_pCollObj->getCollisionPoint(pointCol,true);
        return true;
    }
    return false;
}

float CollisionManager::TestFloorRay(float* origin)
{
    float dir[3] = {0.0f,0.0f,-1.0f};
    if (m_pCollObj->rayCollision(origin,dir,true,0.0f,50.0f))
    {
        m_pCollObj->getCollisionPoint(dir,true);
        return dir[2]+5.0f;
    }
    return *(origin+2);
}

float CollisionManager::getBoundingBox(int indice){
    float vector[6];
    vector[0]=xmin;
    vector[1]=xmax;
    vector[2]=ymin;
    vector[3]=ymax;
    vector[4]=zmin;
    vector[5]=zmax;

    return vector[indice];
}

float CollisionManager::getXmin(){
    return xmin;
}

float CollisionManager::getXmax(){
    return xmax;
}

float CollisionManager::getYmin(){
    return ymin;
}

float CollisionManager::getYmax(){
    return ymax;
}

float CollisionManager::getZmin(){
    return zmin;
}

float CollisionManager::getZmax(){
    return zmax;
}
