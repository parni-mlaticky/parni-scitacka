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
#include <QTextEdit>
#include <QComboBox>

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

void ParniScitacka::on_ButtonRoot_clicked()
{
    Parnilogika::pl->binaryOperation(Parnilogika::pl->ROOT);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonEqual_clicked()
{
    try {
		// Adding the the operands portion (1 + 1 =) to history.
		Parnilogika::pl->history += Parnilogika::pl->getDisplayOutput();
		Parnilogika::pl->history += " = ";

		Parnilogika::pl->processResult();

		// Adding the result to the history.
		Parnilogika::pl->history += Parnilogika::pl->getDisplayOutput();
        Parnilogika::pl->history += "\n";
		ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
	}
	catch (...) {
		Parnilogika::pl->history += "Error\n";
		ParniScitacka::ui->Display->setText("Error");
		Parnilogika::pl->reset();
	}
}

void ParniScitacka::on_ButtonSin_clicked()
{
    Parnilogika::pl->unaryOperation(Parnilogika::pl->SIN);
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonCos_clicked()
{
	Parnilogika::pl->unaryOperation(Parnilogika::pl->COS);
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonTan_clicked()
{
	Parnilogika::pl->unaryOperation(Parnilogika::pl->TAN);
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonCotan_clicked()
{
	Parnilogika::pl->unaryOperation(Parnilogika::pl->COTAN);
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonAns_clicked()
{
	Parnilogika::pl->ansToCollector();
	ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonFact_clicked()
{
	Parnilogika::pl->unaryOperation(Parnilogika::pl->FACT);
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
    std::string history = Parnilogika::pl->history;
     QTextEdit *historyWindow = new QTextEdit();
      historyWindow->setText(QString:: fromStdString(history));
      historyWindow->setReadOnly(true);
      historyWindow->setWindowTitle("Historie");
      historyWindow->show();

}

void ParniScitacka::on_actionPrecision_triggered()
{
    QGridLayout *grid = new QGridLayout(this);
    QComboBox *comboBox = new QComboBox();
    comboBox->addItem("5");
    comboBox->addItem("10");
    comboBox->addItem("14");
    comboBox->setFixedHeight(50);
    comboBox->setFixedWidth(200);
    comboBox->setWindowTitle("Nastavení přesnosti");
    grid->addWidget(comboBox);
    //current value
    //comboBox->itemData(comboBox->currentIndex());
    comboBox->show();

}

void ParniScitacka::on_actionAbout_triggered()
{
       QMessageBox::information(this, "O kalkulačce", ABOUT_MESSAGE);
}

void ParniScitacka::on_ButtonSwitch_clicked()
{
    Parnilogika::pl->invertCollector();
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::on_ButtonBackspace_clicked()
{
    Parnilogika::pl->popCollector();
    ParniScitacka::ui->Display->setText(QString::fromStdString(Parnilogika::pl->getDisplayOutput()));
}

void ParniScitacka::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_0:
        on_Button0_clicked();
        return;
    case Qt::Key_1:
        on_Button1_clicked();
        return;
    case Qt::Key_2:
        on_Button2_clicked();
        return;
    case Qt::Key_3:
        on_Button3_clicked();
        return;;
    case Qt::Key_4:
        on_Button4_clicked();
        return;
    case Qt::Key_5:
        on_Button5_clicked();
        return;
    case Qt::Key_6:
        on_Button6_clicked();
        return;
    case Qt::Key_7:
        on_Button7_clicked();
        return;
    case Qt::Key_8:
        on_Button8_clicked();
        return;
    case Qt::Key_9:
        on_Button9_clicked();
        return;
    case Qt::Key_Period:
        on_ButtonDot_clicked();
        return;
    case Qt::Key_Slash:
        on_ButtonDivide_clicked();
        return;
    case Qt::Key_Asterisk:
        on_ButtonMultiply_clicked();
        return;
    case Qt::Key_Plus:
        on_ButtonPlus_clicked();
        return;
    case Qt::Key_Minus:
        on_ButtonMinus_clicked();
        return;
    case Qt::Key_Return:
        on_ButtonEqual_clicked();
        return;
    case Qt::Key_Enter:
        on_ButtonEqual_clicked();
        return;
    case Qt::Key_Escape:
        on_ButtonReset_clicked();
        return;
    case Qt::Key_E:
        on_ButtonEuler_clicked();
        return;
    case Qt::Key_P:
        on_ButtonPI_clicked();
        return;
    case Qt::Key_S:
        on_ButtonSin_clicked();
        return;
    case Qt::Key_C:
        on_ButtonCos_clicked();
        return;
    case Qt::Key_T:
        on_ButtonTan_clicked();
        return;
    case Qt::Key_F:
        on_ButtonFact_clicked();
        return;
    case Qt::Key_U:
        on_ButtonPow_clicked();
        return;
    case Qt::Key_R:
        on_ButtonRoot_clicked();
        return;
    case Qt::Key_A:
        on_ButtonAns_clicked();
        return;
    case Qt::Key_N:
        on_ButtonSwitch_clicked();
        return;
    case Qt::Key_Backspace:
        on_ButtonBackspace_clicked();
        return;
    }

}

