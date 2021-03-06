/**
* @brief Contains the Parnilogika class which handles the backend of the calculator
* @file parnilogika.h
* @authors Ondřej Zobal, Vladimír Hucovič
*/

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#define PRECISION 16

/**
 * @class Parnilogika
 * @brief Singleton class which is used to connect the math library to the GUI. Contains methods and variables that control
 * the input, output and internal state of the calculator
 */
class Parnilogika {
	public:

	/**
	* @brief Previously entered operand.
	*/
	double accumulator;

	/**
	* @brief Operand that is currently being entered.
	*/
	std::vector<char> collector;

	/**
	* @brief Checks if the collector contains a valid number
	* @return true if the collector contains a valid value
	* @return false if the collector contains an invalid value
	*/
	bool collectorValid;

	/**
	* @brief Checks if collector contains the result of the previous operation
	* @return true if the collector contains the result of the previous operation
	* @return false if the collector does not contain the result of the previous operation
	*/
	bool collectorHasPlaceholder;

	/**
	* @brief Stores the result of the previous operation
	*/
	double ans;

	/**
	* @brief Enum for storing the selected operation
	*/
	enum Operation { UNDEF, SUM, SUB, MUL, DIV, FACT, POW, ROOT, SIN, COS, TAN, COTAN };
	/**
	 * @brief Stores the currently selected operation
	 */
	Operation operation;

	/**
	* @brief String containing endline-separated entries of every calculation
	* done this session.
	*/
	std::string history;

	/**
	* @brief The number of decimal points show on the display.
	*/
	int displayPrecision;

	/**
	* @brief This class is meant to be used as a singleton, this is a static variable, where the reference to the primary instance will be stored.
	*/
	static Parnilogika *pl;

	/**
	* @brief Simply initializes the internal variables.
	*/
	Parnilogika();

	/**
	* @brief Converts a collector vector to a double.
	* @param collector The list of digits that will be converted.
	* @return digits from collector concatenated in a double.
	*/
	static double vecToDouble(std::vector<char> collector);

	/**
	* Collector remains unchanged.
	* @brief Converts the collector to double
	* @return digits from collector concatenated in a double.
	*/
	double collectorToDouble();

	/**
	* @brief Converts and stores the given double to a collector
	* @param f the double that will be put into the collector.
	*/
	void doubleToCollector(double f);

	/**
	* @brief Resets the collector to an empty state.
	*/
	void eraseCollector();

	/**
	* @brief Adds c at the end of the collector.
	* @param c The character that will be added.
	*/
	void appendToCollector(char c);

	/**
	* @brief Removes the last added character from collector. Efectively acts as a backspace
	* @return The character that was removed. If there were no removable characters \0 will be returned.
	*/
	char popCollector();

	/**
	* @brief Moves the value from the collector to the acumulator (and resets the collector)
	*/
	void collectorToAccumulator();

	/**
	* @brief Checks if collector contains a decimal point or not.
	* @return true if collector contains a dot somewhre, otherwite return false.
	*/
	bool isCollectorDecimal();

	/**
	* @brief Clears accumulator, collector and operation.
	*/
	void reset();

	/**
	* @brief Checks whether the number in the collector is negative.
	* @return true if collector is negative
	* @return false if collector is positive
	*/
	bool isCollectorNegative();

	/**
	* @brief Changes the sign of the collector
	*/
	void invertCollector();

	/**
	* Processes the numbers in accumulator and collector and operation.
	* Collector and accumulator remain unchanged.
	* @return The result of the operands and operation
	*/
	void processResult();

	/**
	 * @brief Converts the content of the collector to string
	 * @return Content of collector converted to string
	 */
	std::string collectorToString();

	/**
	* @brief Remove trailing zeroes from the end of the number.
	* @param str The string containing the number
	* @return the number in str but without trailing zeroes at the end.
	*/
	static std::string cutTrailingZeros(std::string str);

	/**
	* @brief sets operation and does additional arrangements needed.
	* this function should be called by every unary operator.
	* @param op the binary operation that will be set.
	*/
	void unaryOperation(Operation op);

	/**
	* @brief sets operation and does additional arrangements needed.
	* this function should be called by every binary operator.
	* @param op the binary operation that will be set.
	*/
	void binaryOperation(Operation op);


	/**
	 * @brief Converts numbers and operations to a format that is then displayed on the calculator screen
	 * @return string that is ready to be displayed on the calculator screen
	 */
	std::string getDisplayOutput();

	/**
	 * @brief Sets the value of the operation variable
	 * @param op the operation to be set
	 */
	void setOperation(Operation op);

	/**
	 * @brief Moves the value of ans to collector
	 */
	void ansToCollector();

	/**
	 * @brief Moves the number Pi to collector
	 */
	void piToCollector();

	/**
	 * @brief Moves Euler's number to collector
	 */
	void eToCollector();
};

