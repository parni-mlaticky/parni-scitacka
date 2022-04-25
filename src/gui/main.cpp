#include "parniscitacka.h"
#include "steammath.h"

#include <QApplication>
#include <iostream>
#include <string>

using namespace sm;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ParniScitacka w;
	w.show();
	return a.exec();
}
