/**
 * A math library
 * */

#include <exception>

/**
 * A function to test it he library is included properly
 * @param one Should be set to the number 1.
 * @return 1 if one is one, otherwise 2.
*/

//TODO: add one more function

namespace sm {
	class SteamMath {
		public:
			static int include_test(int one);

			/**
			* @brief Method to summate numbers
			*
			* @param x first summand
			* @param y second summand
			* @return Summation of the parameter numbers
			*/
			static double sum(double x, double y);

			/**
			* @brief Method to substract numbers
			*
			* @param x minuend
			* @param y substrahend
			* @return Substraction of the parameter numbers
			*/
			static double sub(double x, double y);

			/**
			* @brief Method to multiply numbers
			*
			* @param x multiplier
			* @param y multiplicand
			* @return Multiplication of the parameter numbers
			*/
			static double mul(double x, double y);

			/**
			* @brief Method to divide numbers
			*
			* @param x dividend
			* @param y divisor
			* @return Division of the parameter numbers
			*/
			static double div(double x, double y);

			/**
			* @brief Method to get a factorial of a number
			*
			* @param x number N
			* @return Factorial of the parameter number
			*/
			static double fact(int x);

			/**
			* @brief Method to power number to an exponent
			*
			* @param x base
			* @param y exponent
			* @return Power of the parameter number to the parameter exponent
			*/
			static double pow(double x, int y);

			/**
			* @brief Method to get nth root
			*
			* @param x radicant
			* @param y degree
			* @return Root of the parameter number to the parameter degree
			*/
			static double root(double x, double y);

		private:
			/**
			* Checks for FPU errors. If any are found, raise exception.
			*/
			static void calcErrorCheck();
	};

	/*
	** Exceptions
	*/

	/**
	 * Base exception for calculation errors.
	 * Including overflow and underflow
	 * @param message A message detailing the event.
	 */
	class SmException : std::exception {
	public:
		SmException(char *message);
	};

	/**
	 * Exception signaling that an division by zero has occoured in a calculation
	 * @param message A message detailing the event.
	 */
	class DivisionByZero : sm::SmException {
		using SmException::SmException;
	};

	/**
	 * Exception signaling that ther was a number lesser than one used somewere where it shouldn't.
	 * @param message A message detailing the event.
	 */
	class PositiveNonZeroNumberRequired : sm::SmException {
		using SmException::SmException;
	};
};
