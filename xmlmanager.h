#ifndef XMLLOADER_H
#define XMLLOADER_H

#include "expat/XMLParser.h"
#include "objectmanager.h"

#include <iostream>
#include <fstream>


class XMLManager : public CXMLParser
{
public:
    XMLManager();
    ~XMLManager();

    static XMLManager* getInstance();

    void load(std::string xmlFile, QComboBox* wid);
    void save(std::string xmlPath);

private:
    static XMLManager* instance;
    QComboBox* combo;

    void onStartElement (const std::string &elem, MKeyValue &atts);
};

#endif // XMLLOADER_H
