#include "parniscitacka.h"
#include "steammath.h"
#include "parnilogika.h"

#include <QApplication>
#include <iostream>
#include <string>

using namespace sm;

int main(int argc, char *argv[])
{
	Parnilogika::pl = new Parnilogika();
	// QT magic at work. DON'T TOUCH!
	QApplication a(argc, argv);
	ParniScitacka w;
	w.show();
	return a.exec();
}
