/**
 * A math library containing basic arithmetic operations and some advanced functions like factorial, quadratic
 * function root and goniometric functions
 * @brief Header for the SteamMath math library
 * @file steammath.h
 * @authors Petr Kolouch, Ondřej Zobal, Vladimír Hucovič
 * */

#include <exception>
#include <vector>

/**
 * @namespace sm
 * @brief Namespace for the SteamMath math functions and exceptions
 */
namespace sm {
	/**
	 * @class SteamMath
	 * @brief Class with all SteamMath functions
	 */
	class SteamMath {
		public:
			/**
			* @brief Method to summate numbers
			*
			* @param x first summand
			* @param y second summand
			* @return Summation of the parameter numbers
			*/
			static double sum(double x, double y);

			/**
			* @brief Method to subtract numbers
			*
			* @param x minuend
			* @param y subtrahend
			* @return Subtraction of the parameter numbers
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
			* @param x radicand
			* @param y degree
			* @return Root of the parameter number to the parameter degree
			*/
			static double root(double x, int y);

			/**
			 * This function returns a vector of roots of the input quadratic function (ax^2 + bx + c). It can also
			 * correctly handle input without the quadratic term or an input without both the quadratic and linear
			 * terms
			 * @brief Method to find the roots of a quadratic function (ax^2 + bx + c)
			 * @param a coefficient of the quadratic term
			 * @param b coefficient of the linear term
			 * @param c coefficient of the constant term
			 * @return vector of roots of the quadratic function
			 */
			static std::vector<double> quadRoot(double a, double b, double c);

			/**
			 * @brief Method to calculate the sine of x
			 * @param x the argument for the sine function (in radians)
			 * @return the sine of x
			 */
			static double sin(double x);

			/**
			 * @brief Method to calculate the cosine of x
			 * @param x the argument for the cosine function (in radians)
			 * @return the cosine of x
			 */
			static double cos(double x);

			/**
			 * @brief Method to calculate the tangent of x
			 * @param x the argument for the tangent function (in radians)
			 * @return the tangent of x
			 */
			static double tan(double x);

			/**
			 * @brief Method to calculate the cotangent of x
			 * @param x the argument for the cotangent function (in radians)
			 * @return the cotangent of x
			 */
			static double cotan(double x);

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
	 * @class SmException
	 * @brief Base exception
	 * @param message A message detailing the event.
	 */
	class SmException : std::exception {
	public:
		SmException(const char *message);
	};

	/**
	 * Exception signaling that division by zero has occurred in a calculation
	 * @class DivisionByZero
	 * @brief Exception for a division by zero error
	 * @param message A message detailing the event.
	 */
	class DivisionByZero : sm::SmException {
		using SmException::SmException;
	};

	/**
	 * Exception signaling that the output is undefined for this input
	 * @class OutputUndefined
	 * @brief Exception for when the output is undefined
	 * @param message A message detailing the event.
	 */
	class OutputUndefined : sm::SmException {
		using SmException::SmException;
	};
};
