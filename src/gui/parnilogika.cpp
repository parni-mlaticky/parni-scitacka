#include "parnilogika.h"
#include "../steammath/steammath.h"
#include <string>
#include <iostream>
#include <locale>

using namespace sm;

Parnilogika *Parnilogika::pl = nullptr;

Parnilogika::Parnilogika() {
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
	std::string str = std::to_string(f);
	str = cutTrailingZeros(str);

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
	collectorValid = true;
	collector.push_back(c);
}

char Parnilogika::popCollector() {
	// Poping an empty vector causes segfaults.
	if(collector.size() == 0) {
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
	operation = Parnilogika::Operation::UNDEF;
}

std::vector<double> getQuadRoot(double a, double b, double c){
	// TODO we have to figure out how to handle this
	return SteamMath::quadRoot(a, b ,c);
}

double Parnilogika::processResult() {
	switch (operation) {
		case UNDEF:
			break;
		case SUM:
			doubleToCollector(SteamMath::sum(accumulator, collectorToDouble()));
			std::cout << collectorToString() << std::endl;
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
	ans = accumulator;
	operation = Parnilogika::Operation::UNDEF;
	return 0;
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

std::string Parnilogika::getDisplayOutput() {
	// Bad things happen if the line below isn't there.
	std::setlocale(LC_NUMERIC,"C");
	std::string s;
	switch (operation) {
		case UNDEF:
			s += collectorToString();
			s = cutTrailingZeros(s);
			return s;
		case SUM:
			s = std::to_string(accumulator);
			s = cutTrailingZeros(s);
			s += " + " + collectorToString();
			return s;
		case SUB:
			s = std::to_string(accumulator);
			s = cutTrailingZeros(s);
			s += " - " + collectorToString();
			return s;
		case MUL:
			s = std::to_string(accumulator);
			s = cutTrailingZeros(s);
			s += " * " + collectorToString();
			return s;
		case DIV:
			s = std::to_string(accumulator);
			s = cutTrailingZeros(s);
			s += " / " + collectorToString();
			return s;
		case POW:
			s = std::to_string(accumulator);
			s = cutTrailingZeros(s);
			s += " ^ " + collectorToString();
			return s;
		case ROOT:
			s = std::to_string(accumulator);
			s = cutTrailingZeros(s);
			s += " √ " + collectorToString();
			return s;
		case SIN:
			s = "sin(" + collectorToString() + ")";
			return s;
		case COS:
			s = collectorToString();
		case TAN:
			s = collectorToString();
		case COTAN:
			s = collectorToString();

	}
}
