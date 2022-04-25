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
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}


void ParniScitacka::on_Button1_clicked()
{
    Parnilogika::pl->appendToCollector('1');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_Button2_clicked()
{
    Parnilogika::pl->appendToCollector('2');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_Button3_clicked()
{
    Parnilogika::pl->appendToCollector('3');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_Button4_clicked()
{
    Parnilogika::pl->appendToCollector('4');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_Button5_clicked()
{
    Parnilogika::pl->appendToCollector('5');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_Button6_clicked()
{
    Parnilogika::pl->appendToCollector('6');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_Button7_clicked()
{
    Parnilogika::pl->appendToCollector('7');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_Button8_clicked()
{
    Parnilogika::pl->appendToCollector('8');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_Button9_clicked()
{
    Parnilogika::pl->appendToCollector('9');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_ResetButton_clicked()
{
    Parnilogika::pl->reset();
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}

void ParniScitacka::on_ButtonDot_clicked()
{
    if(Parnilogika::pl->isCollectorDecimal()){
        return;
    }
    Parnilogika::pl->appendToCollector('.');
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->collectorToString()));
}
