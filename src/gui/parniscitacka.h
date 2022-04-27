/**
 * @file parniscitacka.h
 * @brief Contains the ParniScitacka class, which contains the slots and other methods of the Qt main window
 * @authors Vladimír Hucovič, Petr Kolouch
 */

#ifndef PARNISCITACKA_H
#define PARNISCITACKA_H

#include <QMainWindow>


/**
 * @namespace Ui
 * @brief the namespace of the calculator GUI app
 */
QT_BEGIN_NAMESPACE
namespace Ui { class ParniScitacka; }
QT_END_NAMESPACE

/**
 * @class ParniScitacka
 * @brief A class which contains the slots and other methods of the Qt main window
 */
class ParniScitacka : public QMainWindow
{
	Q_OBJECT

public:
	/**
	 * @brief Constructor of the app main window
	 * @param parent parent Element of the window
	 */
	ParniScitacka(QWidget *parent = nullptr);

	/**
	 * @brief Destructor of the app main window
	 */
	~ParniScitacka();

private slots:
    void on_Button0_clicked();
    void on_Button1_clicked();
    void on_Button2_clicked();
    void on_Button3_clicked();
    void on_Button4_clicked();
    void on_Button5_clicked();
    void on_Button6_clicked();
    void on_Button7_clicked();
    void on_Button8_clicked();
    void on_Button9_clicked();
    void on_ButtonReset_clicked();
    void on_ButtonDot_clicked();
    void on_ButtonPlus_clicked();
    void on_ButtonMinus_clicked();
    void on_ButtonMultiply_clicked();
    void on_ButtonDivide_clicked();
    void on_ButtonPow_clicked();
    void on_ButtonSqrt_clicked();
    void on_ButtonEqual_clicked();
    void on_ButtonSin_clicked();
    void on_ButtonCos_clicked();
    void on_ButtonTan_clicked();
    void on_ButtonCotan_clicked();
    void on_ButtonAns_clicked();
	void on_actionAbout_triggered();
	void on_actionHistory_triggered();
    void on_ButtonFact_clicked();
    void on_ButtonEuler_clicked();
    void on_ButtonPI_clicked();

private:
	Ui::ParniScitacka *ui;
};
#endif // PARNISCITACKA_H
