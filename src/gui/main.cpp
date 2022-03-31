#include "parniscitacka.h"
#include "steammath.h"

#include <QApplication>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    int one = SteamMath::include_test(1);
    std::cout << "This is a main for mathlib tests!" << std::to_string(one) << std::endl;
    QApplication a(argc, argv);
    ParniScitacka w;
    w.show();
    return a.exec();
}
