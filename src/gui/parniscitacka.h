/**
 * @file parniscitacka.h
 * @brief Contains the ParniScitacka class, which contains the slots and other methods of the Qt main window
 * @authors Vladimír Hucovič, Petr Kolouch
 */

#ifndef PARNISCITACKA_H
#define PARNISCITACKA_H

#define ABOUT_STRING "<p>Parní sčítačka</p><p>Autoři: Marek Havel, Ondřej Zobal, Vladimír Hucovič, Petr Kolouch</p><p>Ikonka aplikace pochází z balíčku Breeze Icons, distribuovaný pod licencí GPLv3\n</p>"
#define ICON_LINK "<a href=https://github.com/KDE/breeze-icons>Icon source Link</a>"
#define ABOUT_MESSAGE ABOUT_STRING ICON_LINK

#include <QMainWindow>
#include <QKeyEvent>
#include <QComboBox>


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
     * @brief Variable that holds the reference to the ComboBox for selecting precision
     */
    QComboBox *precisionSelect;
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
    /**
     * @brief A function that appends '0' to the collector and refreshes the display.
     */
    void on_Button0_clicked();
    /**
     * @brief A function that appends '1' to the collector and refreshes the display.
     */
    void on_Button1_clicked();
    /**
     * @brief A function that appends '2' to the collector and refreshes the display.
     */
    void on_Button2_clicked();
    /**
     * @brief A function that appends '3' to the collector and refreshes the display.
     */
    void on_Button3_clicked();
    /**
     * @brief A function that appends '4' to the collector and refreshes the display.
     */
    void on_Button4_clicked();
    /**
     * @brief A function that appends '5' to the collector and refreshes the display.
     */
    void on_Button5_clicked();
    /**
     * @brief A function that appends '6' to the collector and refreshes the display.
     */
    void on_Button6_clicked();
    /**
     * @brief A function that appends '7' to the collector and refreshes the display.
     */
    void on_Button7_clicked();
    /**
     * @brief A function that appends '8' to the collector and refreshes the display.
     */
    void on_Button8_clicked();
    /**
     * @brief A function that appends '9' to the collector and refreshes the display.
     */
    void on_Button9_clicked();
    /**
     * @brief A function that resets the state of the calculator to default and refreshes the display
     */
    void on_ButtonReset_clicked();
    /**
     * @brief A function that adds a decimal point to the collector
     */
    void on_ButtonDot_clicked();
    /**
     * @brief A function that sets the operation to plus
     */
    void on_ButtonPlus_clicked();
    /**
     * @brief A function that sets the operation to minus
     */
    void on_ButtonMinus_clicked();
    /**
     * @brief A function that sets the operation to multiplication
     */
    void on_ButtonMultiply_clicked();
    /**
     * @brief A function that sets the operation to division
     */
    void on_ButtonDivide_clicked();
    /**
     * @brief A function that sets the operation to power
     */
    void on_ButtonPow_clicked();
    /**
     * @brief A function that sets the operation to nth root
     */
    void on_ButtonRoot_clicked();
    /**
     * @brief A function that calls the function which calculates the result of the operation, then refreshes the display
     */
    void on_ButtonEqual_clicked();
    /**
     * @brief A function that sets the operation to sine
     */
    void on_ButtonSin_clicked();
    /**
     * @brief A function that sets the operation to cosine
     */
    void on_ButtonCos_clicked();
    /**
     * @brief A function that sets the operation to tangent
     */
    void on_ButtonTan_clicked();
    /**
     * @brief A function that sets the operation to cotangent
     */
    void on_ButtonCotan_clicked();
    /**
     * @brief A function that places the previous result to the collector and refreshes the display
     */
    void on_ButtonAns_clicked();
    /**
     * @brief A function that displays the "about" window
     */
	void on_actionAbout_triggered();
    /**
     * @brief A function that displays the "history" window
     */
	void on_actionHistory_triggered();
    /**
     * @brief A function that sets the operation to factorial
     */
    void on_ButtonFact_clicked();
    /**
     * @brief A function that places Euler's number to collector and refreshes the display
     */
    void on_ButtonEuler_clicked();
    /**
     * @brief A function that places the number Pi to collector and refreshes the display
     */
    void on_ButtonPI_clicked();
    /**
     * @brief A function that inverts the sign of the collector and refreshes the display
     */
    void on_ButtonSwitch_clicked();
    /**
     * @brief A function that removes the last digit from collector and refreshes the display
     */
    void on_ButtonBackspace_clicked();
	/**
	 * @brief A function that opens the precision selection menu
	 */
    void on_actionPrecision_triggered();
	/**
	 * @brief Function that gets called when the precision is changed in the ComboBox precision menu
	 * @param index of the ComboBox selection
	 */
    void on_ComboBox_index_changed(int value);

    void on_actionPrecision_triggered();

protected:
	/**
	 * @brief This function is called whenever a keyboard button is pressed and enables the user to control the app
	 * with their keyboard
	 * @param event An object containing information about the event.
	 */
    void keyPressEvent(QKeyEvent* event);

private:
	Ui::ParniScitacka *ui;
};
#endif // PARNISCITACKA_H
