#include "parniscitacka.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ParniScitacka w;
    w.show();
    return a.exec();
}
