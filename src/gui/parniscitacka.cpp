#include "parniscitacka.h"
#include "ui_parniscitacka.h"
#include <iostream>

ParniScitacka::ParniScitacka(QWidget *parent) : QMainWindow(parent), ui(new Ui::ParniScitacka) {
	ui->setupUi(this);
}

ParniScitacka::~ParniScitacka() {
	delete ui;
}

void ParniScitacka::customActionTest(){
    std::cout << "Different test" << std::endl;
}

void ParniScitacka::on_btnNum0_clicked(){
    std::cout << "Different test" << std::endl;
}

void ParniScitacka::on_btnNum1_clicked(){
    std::cout << "Different test" << std::endl;
}
