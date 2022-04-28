/**
 * @file parnilogika.cpp
 * @authors Ondřej Zobal, Vladimír Hucovič
 * @brief Contains the definitions of functions that control the backend of the calculator
 */

#include "parnilogika.h"
#include "../steammath/steammath.h"
#include <string>
#include <iostream>
#include <locale>
#include <sstream>


using namespace sm;

Parnilogika *Parnilogika::pl = nullptr;

Parnilogika::Parnilogika() {
	displayPrecision = 5;
	std::setlocale(LC_NUMERIC,"C");
	Parnilogika::reset();
}

double Parnilogika::vecToDouble(std::vector<char> collector){
	char *buffer = new char[collector.size()+1];
	std::copy(collector.begin(), collector.end(), buffer);
	buffer[collector.size()] = '\0';

	// save old locale
	const std::string oldLocale=std::setlocale(LC_NUMERIC,nullptr);

	double result;
	// In case the conversion doesn't go so well...
	try {
		// New locale to ensure decimal point
		std::setlocale(LC_NUMERIC,"C");
		result = std::stod(buffer);
		// restore previous locale
	}
	catch (...) {
		result = 0;
	}
	std::setlocale(LC_NUMERIC,oldLocale.c_str());

	delete[] buffer;
	return result;
}

double Parnilogika::collectorToDouble() {
	return Parnilogika::vecToDouble(collector);
}

void Parnilogika::doubleToCollector(double f) {
	eraseCollector();

	std::setlocale(LC_NUMERIC,"C");
	std::ostringstream out;
	out.precision(PRECISION);
	out << std::fixed << f;
	std::string str = cutTrailingZeros(out.str());

	for (int i = 0; (size_t) i < str.length(); i++) {
		appendToCollector(str[i]);
	}

}

void Parnilogika::eraseCollector() {
	// FIXME I dont think i need to call a destructor on the old collector
	// because I didnt use "new" to create it, but I am not sure.
	// I dont know how magical this steammachine of a language is...
	collector = std::vector<char>();
}

void Parnilogika::appendToCollector(char c) {
	if(collectorHasPlaceholder) {
		eraseCollector();
	collectorHasPlaceholder = false;
	}
	collectorValid = true;
	collector.push_back(c);
}

char Parnilogika::popCollector() {
	// Poping an empty vector causes segfaults.
	if(collector.size() == 0) {
		return '\0';
	}

	if(collectorHasPlaceholder) {
		eraseCollector();
		return '\0';
	}

	char c = collector[collector.size()-1];
	collector.pop_back();
	return c;
}

void Parnilogika::collectorToAccumulator() {
	accumulator = collectorToDouble();
	eraseCollector();
}

bool Parnilogika::isCollectorDecimal() {
	for (char c : collector) {
		if (c == '.') {
			return true;
		}
	}
	return false;
}

void Parnilogika::reset() {
	accumulator = 0;
	collector = std::vector<char>();
	collectorValid = false;
	collectorHasPlaceholder = false;
	operation = Parnilogika::Operation::UNDEF;
}

void Parnilogika::processResult() {
	if(collectorHasPlaceholder) {
		return;
	}
	switch (operation) {
		case UNDEF:
			break;
		case SUM:
			doubleToCollector(SteamMath::sum(accumulator, collectorToDouble()));
			 break;
		case SUB:
			doubleToCollector(SteamMath::sub(accumulator, collectorToDouble()));
			break;
		case MUL:
			doubleToCollector(SteamMath::mul(accumulator, collectorToDouble()));
			break;
		case DIV:
			doubleToCollector(SteamMath::div(accumulator, collectorToDouble()));
			break;
		case FACT:
			doubleToCollector(SteamMath::fact(collectorToDouble()));
			break;
		case POW:
			doubleToCollector(SteamMath::pow(accumulator, collectorToDouble()));
			break;
		case ROOT:
			doubleToCollector(SteamMath::root(collectorToDouble(), accumulator));
			break;
		case SIN:
			doubleToCollector(SteamMath::sin(collectorToDouble()));
			break;
		case COS:
			doubleToCollector(SteamMath::cos(collectorToDouble()));
			break;
		case TAN:
			doubleToCollector(SteamMath::tan(collectorToDouble()));
			break;
		case COTAN:
			doubleToCollector(SteamMath::tan(collectorToDouble()));
			break;
	}
	ans = collectorToDouble();
	operation = Parnilogika::Operation::UNDEF;
	collectorHasPlaceholder = true;
}

bool Parnilogika::isCollectorNegative() {
	if(collector.size() == 0) {
		return false;
	}
	return collector[0] == '-';
}

void Parnilogika::invertCollector() {
	if(collector.size() == 0) {
		return;
	}
	if(Parnilogika::isCollectorNegative()) {
		collector.erase(collector.begin());
	}
	else {
		collector.insert(collector.begin(), '-');
	}
}

std::string Parnilogika::collectorToString(){
    std::string s(collector.begin(), collector.end());
    return s;
}

void Parnilogika::setOperation(Operation op){
	operation = op;
}

std::string Parnilogika::cutTrailingZeros(std::string str) {
	// Cutting zeros from the end
	bool hasDecimal = false;
	for (char c : str) {
		if (c == '.') {
			hasDecimal = true;
			break;
		}
	}

	if (!hasDecimal) {
		return str;
	}

	for (int i = str.size()-1; i > 0; i--) {
		if(str[i] == '0') {
			str.erase(i, 1);
		}
		else if(str[i] == '.') {
			str.erase(i, 1);
			break;
		}
		else {
			break;
		}
	}
	return str;
}

void Parnilogika::unaryOperation(Operation op) {
	// The nature of unary operations allows it to use placeholder value
	// in form of a result from previous calculation.
	collectorHasPlaceholder = false;

    setOperation(op);
}

void Parnilogika::binaryOperation(Operation op) {
	if(collectorValid && (operation != UNDEF)){
		processResult();
	}

	// Only overwrite the current acc if collector has real data in it.
	if(collectorValid) {
		collectorToAccumulator();
		collectorValid = false;
	}
    setOperation(op);
}

void Parnilogika::ansToCollector(){
	doubleToCollector(ans);
}

void Parnilogika::piToCollector() {
	doubleToCollector(SteamMath::const_pi());
}

void Parnilogika::eToCollector() {
	doubleToCollector(SteamMath::const_e());
}

std::string Parnilogika::getDisplayOutput() {
	// Bad things happen if the line below isn't there.
	std::setlocale(LC_NUMERIC,"C");
	std::string s;
	std::ostringstream out;
	out.precision(displayPrecision);

	switch (operation) {
		case UNDEF:
			if (collectorHasPlaceholder) {
				std::ostringstream out;
				out.precision(displayPrecision);

				out << std::fixed << collectorToDouble();
				s = cutTrailingZeros(out.str());
			}
			else {
				s += collectorToString();
			}

			return s;
		case SUM:
			out << std::fixed << accumulator;
			s = out.str();
			s = cutTrailingZeros(s);
			s += " + " + collectorToString();
			return s;
		case SUB:
			out << std::fixed << accumulator;
			s = out.str();
			s = cutTrailingZeros(s);
			s += " - " + collectorToString();
			return s;
		case MUL:
			out << std::fixed << accumulator;
			s = out.str();
			s = cutTrailingZeros(s);
			s += " * " + collectorToString();
			return s;
		case DIV:
			out << std::fixed << accumulator;
			s = out.str();
			s = cutTrailingZeros(s);
			s += " / " + collectorToString();
			return s;
		case POW:
			out << std::fixed << accumulator;
			s = out.str();
			s = cutTrailingZeros(s);
			s += " ^ " + collectorToString();
			return s;
		case ROOT:
			out << std::fixed << accumulator;
			s = out.str();
			s = cutTrailingZeros(s);
			s += " √ " + collectorToString();
			return s;
		case FACT:
			s = collectorToString() + "!";
			return s;
		case SIN:
			s = "sin(" + collectorToString() + ")";
			return s;
		case COS:
			s = "cos(" + collectorToString() + ")";
			return s;
		case TAN:
			s = "tan(" + collectorToString() + ")";
			return s;
		case COTAN:
			s = "cotan(" + collectorToString() + ")";
			return s;

	}
}
