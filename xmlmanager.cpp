#include "xmlmanager.h"

XMLManager* XMLManager::instance = NULL;

XMLManager::XMLManager()
{
}

XMLManager::~XMLManager()
{
}

XMLManager* XMLManager::getInstance()
{
    if (!instance) {
        instance = new XMLManager();
    }
    return instance;
}

void XMLManager::load(std::string xmlFile)
{
    xmlParseFile(xmlFile);
}

void XMLManager::save(std::string xmlPath)
{
    std::ofstream outfile;

    outfile.open(xmlPath.c_str());

    outfile << "<MUSEU>" << std::endl;

    std::vector<Object*>::iterator iter;

    sgVec3 pos;
    sgVec3 esc;
    sgQuat rot;

    for (iter = ObjectManager::getInstance()->FirstObject(); iter != ObjectManager::getInstance()->LastObject(); ++iter)
    {
        sgCopyVec3(pos,(*iter)->posicio);
        sgCopyVec3(esc,(*iter)->escala);
        sgCopyQuat(rot,(*iter)->rotacio);

        outfile << "  <OBJECTE";
        outfile << " name=\"" << (*iter)->name <<"\"";
        outfile << " model=\"" << (*iter)->pathmodel <<"\"";

        outfile << " posx=\"" << pos[0] << "\"";
        outfile << " posy=\"" << pos[1] << "\"";
        outfile << " posz=\"" << pos[2] << "\"";

        outfile << " escx=\"" << esc[0] << "\"";
        outfile << " escy=\"" << esc[1] << "\"";
        outfile << " escz=\"" << esc[2] << "\"";

        outfile << " rotw=\"" << rot[0] << "\"";
        outfile << " rotx=\"" << rot[1] << "\"";
        outfile << " roty=\"" << rot[2] << "\"";
        outfile << " rotz=\"" << rot[3] << "\"";
        outfile << " />" << std::endl;
    }

    outfile << "</MUSEU>";

    outfile.close();
}

void XMLManager::onStartElement(const std::string &elem, MKeyValue &atts)
{
    if (elem == "OBJECTE")
    {
        sgVec3 pos, esc;
        sgQuat rot;

        std::string model = atts["model"];
        std::string nom = atts["name"];

        QString posx = atts["posx"].c_str();
        QString posy = atts["posy"].c_str();
        QString posz = atts["posz"].c_str();

        pos[0] = posx.toFloat();
        pos[1] = posy.toFloat();
        pos[2] = posz.toFloat();

        QString escx = atts["escx"].c_str();
        QString escy = atts["escy"].c_str();
        QString escz = atts["escz"].c_str();

        esc[0] = escx.toFloat();
        esc[1] = escy.toFloat();
        esc[2] = escz.toFloat();

        QString rotw = atts["rotw"].c_str();
        QString rotx = atts["rotx"].c_str();
        QString roty = atts["roty"].c_str();
        QString rotz = atts["rotz"].c_str();

        rot[0] = rotw.toFloat();
        rot[1] = rotx.toFloat();
        rot[2] = roty.toFloat();
        rot[3] = rotz.toFloat();

        ObjectManager::getInstance()->AddObject(nom,pos,esc,rot,model);
    }
}
