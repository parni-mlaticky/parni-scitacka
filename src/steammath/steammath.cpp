/**
 * @brief Implementation of the functions of SteamMath library
 * @file steammath.cpp
 * @authors Vladimír Hucovič, Ondřej Zobal
 */

#include "steammath.h"
#include <cmath>
#include <iostream>
#include <cfenv>
#include <limits>

using namespace sm;

void SteamMath::calcErrorCheck() {
	// Test all errors supported by architectures FPU.
	if (std::fetestexcept(FE_ALL_EXCEPT)) {
		throw SmException("Error during an operation");
	}

	if (std::fetestexcept(FE_DIVBYZERO)) {
		throw DivisionByZero("Division by zero detected");
	}
}

double SteamMath::sum(double x, double y) {
	std::feclearexcept(FE_ALL_EXCEPT);

	double result = x + y;

	SteamMath::calcErrorCheck();
	return result;
}

double SteamMath::sub(double x, double y) {
	std::feclearexcept(FE_ALL_EXCEPT);

	double result = x - y;

	SteamMath::calcErrorCheck();
	return result;
}

double SteamMath::mul(double x, double y) {
	std::feclearexcept(FE_ALL_EXCEPT);

	double result = x * y;

	SteamMath::calcErrorCheck();
	return result;
}

double SteamMath::div(double x, double y) {
	if (y == 0) {
		throw DivisionByZero("Division by zero");
	}

	std::feclearexcept(FE_ALL_EXCEPT);

	double result = x / y;

	// FIXME division seems to set off some unexpexted flags.
	//SteamMath::calcErrorCheck();
	return result;
}

double SteamMath::fact(int x) {
	if (x < 0) {
		throw OutputUndefined("x has to be greater then zero");
	}

	if (x == 0 || x == 1) {
		return 1;
	}

	std::feclearexcept(FE_ALL_EXCEPT);

	double result = x;
	for (int i = x-1; i > 1; i--) {
		result *= i;
	}

	SteamMath::calcErrorCheck();
	return result;
}

double SteamMath::pow(double x, int y) {
	if (y < 0) {
		throw OutputUndefined("y has to be greater then zero");
	}
	std::feclearexcept(FE_ALL_EXCEPT);

	if(y == 0){
		return 1;
	}

	double result = x;
	for (int i = 0; i < y-1; i++) {
		result *= x;
	}

	SteamMath::calcErrorCheck();
	return result;
}

double SteamMath::root(double x, int y) {
	std::feclearexcept(FE_ALL_EXCEPT);

	if(y % 2 == 0 && x < 0){
		throw OutputUndefined("Even nth root of a negative number is not a real number");
	}

	if(y == 0){
		throw OutputUndefined("Root of degree 0 is not defined");
	}

	double result = std::pow(x,  (1.0/y));

	return result;
}

std::vector<double> SteamMath::quadRoot(double a, double b, double c){
	double discriminant = SteamMath::pow(b, 2) - (4*a*c);
	if(discriminant < 0){
		throw OutputUndefined("Discriminant is negative; the roots are not real");
	}
	if(a == 0 && b == 0){
		throw OutputUndefined("For a == b == 0 , the output could either be anything (c==0) or nothing (c != 0)");
	}

	std::vector<double> result;

	if(a == 0){
		double x = c / (-b);
		result.push_back(x);
		result.push_back(x);
		return result;
	}
	if(b == 0){
		double x1 = -SteamMath::root(-c, 2);
		double x2 = -x1;
		result.push_back(x1);
		result.push_back(x2);
		return result;
	}

	double x1 = (-b + SteamMath::root(discriminant, 2)) / (2*a);
	double x2 = (-b - SteamMath::root(discriminant, 2)) / (2*a);

	result.push_back(x1);
	result.push_back(x2);

	return result;
}

double SteamMath::sin(double x){
	double result = std::sin(x);
	return result;
}

double SteamMath::cos(double x) {
	double result = std::cos(x);
	return result;
}

double SteamMath::tan(double x) {
	if(std::abs(std::cos(x)) < std::numeric_limits<double>::epsilon()){
		throw OutputUndefined("Tangent is undefined (infinity) for this value");
	}

	double result = std::tan(x);
	return result;
}

double SteamMath::cotan(double x) {
	if(std::abs(std::sin(x)) < std::numeric_limits<double>::epsilon()){
		throw OutputUndefined("Cotangent is undefined (infinity) for this value");
	}

	double result = 1 / std::tan(x);
	return result;
}

SmException::SmException(const char* message) {
	std::cout << message << std::endl;
}
