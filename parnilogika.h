#include <vector>

class Parnilogika {
	// Previously entered operand.
	double accumulator;
	// Operand that is currently beeing entered.
	Vector<char> collector;
	// Enum for storing the selected operation
	// TODO add more.
	enum Operation = { UNDEF, ADD, SUB, MUL, DIV };
	Operation operation;

	/**
	* Converts the collector vector to a double.
	* @param collector The list of digits that will be converted.
	* @sing The sign of the number in collector (true is negative, false is positive).
	* @return digits from collector concated in a double.
	*/
	double collectorToDouble(Vector<char> collector);

	/**
	* Pocesses the numbers and operation.
	* @param x first operand.
	* @param y second operand.
	* @param operation The operation that will be carried out.
	* @return The result of the operands and operation.
	*/
	double processResult(double x, double y, Operation operation);
}
