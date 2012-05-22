#include "xmlruta.h"


xmlRuta* xmlRuta::instance = NULL;

xmlRuta::xmlRuta()
{
}

xmlRuta::~xmlRuta()
{
}

xmlRuta* xmlRuta::getInstance()
{
    if (!instance) {
        instance = new xmlRuta();
    }
    return instance;
}

void xmlRuta::load(std::string xmlFile)
{
    xmlParseFile(xmlFile);
}


void xmlRuta::onStartElement(const std::string &elem, MKeyValue &atts)
{
    if (elem == "Pos")
    {
        QString x = atts["x"].c_str();
        QString y = atts["y"].c_str();
        WayManager::getInstance()->addwayPoint(x.toFloat(),y.toFloat());
    }
}
