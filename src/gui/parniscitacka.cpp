/**
 * @file parniscitacka.cpp
 * @authors Vladimír Hucovič, Petr Kolouch
 * @brief module that contains the definition of functions that get called when buttons are pressed
 */

#include "parniscitacka.h"
#include "ui_parniscitacka.h"
#include "parnilogika.h"
#include <iostream>
#include <QMessageBox>

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
    Parnilogika::pl->binaryOperation(Parnilogika::pl->SUM);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonMinus_clicked()
{
    Parnilogika::pl->binaryOperation(Parnilogika::pl->SUB);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonMultiply_clicked()
{
    Parnilogika::pl->binaryOperation(Parnilogika::pl->MUL);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonDivide_clicked()
{
    Parnilogika::pl->binaryOperation(Parnilogika::pl->DIV);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}


void ParniScitacka::on_ButtonPow_clicked()
{
    Parnilogika::pl->binaryOperation(Parnilogika::pl->POW);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonSqrt_clicked()
{
    Parnilogika::pl->binaryOperation(Parnilogika::pl->ROOT);
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

void ParniScitacka::on_ButtonCos_clicked()
{
	Parnilogika::pl->setOperation(Parnilogika::pl->COS);
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonTan_clicked()
{
	Parnilogika::pl->setOperation(Parnilogika::pl->TAN);
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonCotan_clicked()
{
	Parnilogika::pl->setOperation(Parnilogika::pl->COTAN);
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonAns_clicked()
{
	Parnilogika::pl->ansToCollector();
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonFact_clicked()
{
	Parnilogika::pl->setOperation(Parnilogika::pl->FACT);
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonEuler_clicked()
{
	Parnilogika::pl->eToCollector();
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonPI_clicked()
{
	Parnilogika::pl->piToCollector();
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}


void ParniScitacka::on_actionHistory_triggered()
{
    QMessageBox::information(this, "History", "TODO");
}

void ParniScitacka::on_actionAbout_triggered()
{
	QMessageBox::information(this, "About", "Epická parní kalkulačka vytvořená Zobem, Vladem, Marem a Kolem");
}

void ParniScitacka::on_ButtonSwitch_clicked()
{
    Parnilogika::pl->invertCollector();
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));

}
