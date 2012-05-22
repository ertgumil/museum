#ifndef XMLRUTA_H
#define XMLRUTA_H


#endif // XMLRUTA_H
#include "expat/XMLParser.h"
#include "waymanager.h"

#include <iostream>
#include <fstream>


class xmlRuta : public CXMLParser
{
public:
    xmlRuta();
    ~xmlRuta();

    static xmlRuta* getInstance();

    void load(std::string xmlFile);

private:
    static xmlRuta* instance;

    void onStartElement (const std::string &elem, MKeyValue &atts);
};
