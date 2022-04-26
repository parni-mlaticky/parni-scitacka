#include "parniscitacka.h"
#include "ui_parniscitacka.h"
#include "parnilogika.h"
#include <iostream>

ParniScitacka::ParniScitacka(QWidget *parent) : QMainWindow(parent), ui(new Ui::ParniScitacka) {
	ui->setupUi(this);


}

ParniScitacka::~ParniScitacka() {
	delete ui;
}

void ParniScitacka::on_Button0_clicked()
{
    Parnilogika::pl->appendToCollector('0');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}


void ParniScitacka::on_Button1_clicked()
{
    Parnilogika::pl->appendToCollector('1');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_Button2_clicked()
{
    Parnilogika::pl->appendToCollector('2');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_Button3_clicked()
{
    Parnilogika::pl->appendToCollector('3');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_Button4_clicked()
{
    Parnilogika::pl->appendToCollector('4');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_Button5_clicked()
{
    Parnilogika::pl->appendToCollector('5');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_Button6_clicked()
{
    Parnilogika::pl->appendToCollector('6');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_Button7_clicked()
{
    Parnilogika::pl->appendToCollector('7');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_Button8_clicked()
{
    Parnilogika::pl->appendToCollector('8');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_Button9_clicked()
{
    Parnilogika::pl->appendToCollector('9');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonReset_clicked()
{
    Parnilogika::pl->reset();
    ParniScitacka::ui->Display->setText(QString::fromStdString("0"));
}

void ParniScitacka::on_ButtonDot_clicked()
{
    if(Parnilogika::pl->isCollectorDecimal()){
        return;
    }
    Parnilogika::pl->appendToCollector('.');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonPlus_clicked()
{
	Parnilogika::Operation op = Parnilogika::pl->SUM;
//	if(op == Parnilogika::pl->operation){
//		return;
//	}
    Parnilogika::pl->collectorToAccumulator();
    Parnilogika::pl->setOperation(op);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonMinus_clicked()
{
	Parnilogika::Operation op = Parnilogika::pl->SUB;
//	if(op == Parnilogika::pl->operation){
//		return;
//	}
    Parnilogika::pl->collectorToAccumulator();
    Parnilogika::pl->setOperation(Parnilogika::pl->SUB);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonMultiply_clicked()
{
    Parnilogika::pl->collectorToAccumulator();
    Parnilogika::pl->setOperation(Parnilogika::pl->MUL);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonDivide_clicked()
{
    Parnilogika::pl->collectorToAccumulator();
    Parnilogika::pl->setOperation(Parnilogika::pl->DIV);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}


void ParniScitacka::on_ButtonPow_clicked()
{
    Parnilogika::pl->collectorToAccumulator();
    Parnilogika::pl->setOperation(Parnilogika::pl->POW);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonSqrt_clicked()
{
    Parnilogika::pl->collectorToAccumulator();
    Parnilogika::pl->setOperation(Parnilogika::pl->ROOT);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonEqual_clicked()
{
    Parnilogika::pl->processResult();
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonSin_clicked()
{
    Parnilogika::pl->setOperation(Parnilogika::pl->SIN);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}
