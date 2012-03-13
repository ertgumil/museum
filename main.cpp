#include <QtGui/QApplication>
#include "uigc2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UIGC2 w;
    w.show();

    return a.exec();

}
