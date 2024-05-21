#include "puissancequatre.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PuissanceQuatre w;
    w.show();

    return a.exec();
}
