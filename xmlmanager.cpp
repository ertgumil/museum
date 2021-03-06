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

void XMLManager::load(std::string xmlFile, QComboBox *wid)
{
    combo = wid;
    xmlParseFile(xmlFile);
}

void XMLManager::save(std::string xmlPath)
{
    std::ofstream outfile;

    outfile.open(xmlPath.c_str());

    outfile << "<MUSEU>" << std::endl;

    std::vector<Object*>::iterator iter;

    QVector3D pos;
    QVector3D esc;
    QQuaternion rot;

    for (iter = ObjectManager::getInstance()->FirstObject(); iter != ObjectManager::getInstance()->LastObject(); ++iter)
    {
        pos = (*iter)->posicio;
        esc = (*iter)->escala;
        rot = (*iter)->rotacio;
        std::string line1 = (*iter)->pathmodel;
        QString lin2 = QString(line1.c_str());
        QRegExp rx( "[a-zA-Z\/]+/models" );      // match ampersands but not &amp;
        lin2.replace( rx, "models" );
        qDebug("A string: %s", qPrintable(lin2));
        line1 = lin2.toStdString();


        outfile << "  <OBJECTE";
        outfile << " name=\"" << (*iter)->name <<"\"";
        outfile << " model=\"" << line1 <<"\"";

        outfile << " posx=\"" << pos.x() << "\"";
        outfile << " posy=\"" << pos.y() << "\"";
        outfile << " posz=\"" << pos.z() << "\"";

        outfile << " escx=\"" << esc.x() << "\"";
        outfile << " escy=\"" << esc.y() << "\"";
        outfile << " escz=\"" << esc.z() << "\"";

        outfile << " rotw=\"" << rot.scalar() << "\"";
        outfile << " rotx=\"" << rot.x() << "\"";
        outfile << " roty=\"" << rot.y() << "\"";
        outfile << " rotz=\"" << rot.z() << "\"";
        outfile << " />" << std::endl;
    }

    outfile << "</MUSEU>";

    outfile.close();
}

void XMLManager::onStartElement(const std::string &elem, MKeyValue &atts)
{
    if (elem == "OBJECTE")
    {
        QVector3D pos, esc;
        QQuaternion rot;


        std::string model = atts["model"];
        std::string nom = atts["name"];

        QString posx = atts["posx"].c_str();
        QString posy = atts["posy"].c_str();
        QString posz = atts["posz"].c_str();

        pos = QVector3D(posx.toFloat(),
                        posy.toFloat(),
                        posz.toFloat());

        QString escx = atts["escx"].c_str();
        QString escy = atts["escy"].c_str();
        QString escz = atts["escz"].c_str();

        esc = QVector3D(escx.toFloat(),
                        escy.toFloat(),
                        escz.toFloat());

        QString rotw = atts["rotw"].c_str();
        QString rotx = atts["rotx"].c_str();
        QString roty = atts["roty"].c_str();
        QString rotz = atts["rotz"].c_str();

        rot = QQuaternion(rotw.toFloat(),
                          rotx.toFloat(),
                          roty.toFloat(),
                          rotz.toFloat());

        QString name = QString::fromStdString(nom);
        QString path = QString::fromStdString(model);

        ObjectManager::getInstance()->AddObject(name,pos,esc,rot,path);

        if (combo != NULL)
            combo->addItem(name);
    }
}
