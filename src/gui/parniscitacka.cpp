#include "parniscitacka.h"
#include "ui_parniscitacka.h"

ParniScitacka::ParniScitacka(QWidget *parent) : QMainWindow(parent), ui(new Ui::ParniScitacka) {
	ui->setupUi(this);
}

ParniScitacka::~ParniScitacka() {
	delete ui;
}
