#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
/**
* A singleton class, holding internal state and logic of the calculator backend.
* @file parnilogika.h
* @authors Ondřej Zobal, Vladimír Hucovič
* @todo changeCollectorSign Adds or removes - at the beginning of the collector.
* @todo We may need to condiser input validation,
* but that may not be needed since the use wont be inputing the numbers directly into the collector.
*/

class Parnilogika {
	public:

	/**
	* Previously entered operand.
	*/
	double accumulator;

	/**
	* Operand that is currently beeing entered.
	*/
	std::vector<char> collector;

	/**
	 * True, when collector contains a valid value.
	 * Might be false when the user hasn't inputed anything into the collector.
	 */
	bool collectorValid;

	/**
	 * Result of the previous operation
	 */
	double ans;

	/**
	* Enum for storing the selected operation
	* @todo TODO add more.
	*/
	enum Operation { UNDEF, SUM, SUB, MUL, DIV, FACT, POW, ROOT, QUAD, SIN, COS, TAN, COTAN };
	Operation operation;

	/**
	* This class is ment to be used as a singleton, this is a static variable, where the refference to the primary instance will be stored.
	*/
	static Parnilogika *pl;
	/**
	* Simply initializes the internal variables.
	*/
	Parnilogika();

	/**
	* Converts a collector vector to a double.
	* @param collector The list of digits that will be converted.
	* @return digits from collector concated in a double.
	*/
	static double vecToDouble(std::vector<char> collector);

	/**
	* Converts the collector of this object to a double.
	* Collector remains unchanged.
	* @return digits from collector concated in a double.
	*/
	double collectorToDouble();

	/**
	* Converts and storest the given double to a collector
	* @param the double that will be put into the collector.
	*/
	void doubleToCollector(double f);

	/**
	* Resets the collector to an empty state.
	*/
	void eraseCollector();

	/**
	* Adds c at the end of the collector.
	* @param c The character that will be added.
	*/
	void appendToCollector(char c);

	/**
	* Removes the last added character from collector. Efectively acts as a backspace
	* @return The character that was removed. There were no removable characters \0 will be returned.
	*/
	char popCollector();

	/**
	* Moves the value from the collector to the acumulator (and resets the collector)
	*/
	void collectorToAccumulator();

	/**
	* Tells you if collector contains a decimal point or not.
	* @return true if collector contains a dot somewhre, otherwite return false.
	*/
	bool isCollectorDecimal();

	/**
	* Clears accumulator, collector and operation.
	*/
	void reset();

	/**
	* Tells you, whther the collector contains is negative.
	* @return true if collector begins with a minus.
	*/
	bool isCollectorNegative();

	/**
	* Changes the sign of the collector
	*/
	void invertCollector();

	/**
	* Pocesses the numbers and operation.
	* @param x first operand.
	* @param y second operand.
	* @param operation The operation that will be carried out.
	* @return The result of the operands and operation.
	*/

	std::vector<double> getQuadRoot(double a, double b, double c);

	/**
	* Pocesses the numbers in accumulator and collector and operation.
	* Collector and accumulator remain unchanged.
	* @return The result of the operands and operation
	*/
	double processResult();

	/**
	 * @brief Converts the content of the collector to string
	 * @return content of collector converted to string
	 */
	std::string collectorToString();

	/**
	* Remove trailing zeroes from the end of the number.
	* @param str The string containing the number
	* @return the number in str but without trailing zeroes at the end.
	*/
	static std::string cutTrailingZeros(std::string str);

	/**
	* Sets operation and does aditional arrangements needed.
	* This function should be called by every binary operator.
	* @param op The binary operation that will be set.
	*/
void binaryOperation(Operation op);


	/**
	 * @brief converts numbers and operations to a format that is then displayed on the calculator screen
	 * @param operation currently selected operation
	 * @return string that is ready to be displayed on the calculator screen
	 */
	std::string getDisplayOutput();

	void setOperation(Operation op);
};
