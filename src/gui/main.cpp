/**
 * @file main.cpp
 * @authors Ondeřej Zobal
 * @brief Contains the main function of the app, which starts the calculator
 */

#include "parniscitacka.h"
#include "steammath.h"
#include "parnilogika.h"

#include <QApplication>
#include <iostream>
#include <string>

using namespace sm;

/**
 * Main function. It creates the necessary objects and starts the calculator
 * @param argc argument count
 * @param argv vector of arguments
 */
int main(int argc, char *argv[])
{
	Parnilogika::pl = new Parnilogika();
	// QT magic at work. DON'T TOUCH!
	QApplication a(argc, argv);
	ParniScitacka w;
	w.show();
	return a.exec();
}
