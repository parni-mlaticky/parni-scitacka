#include "parnilogika.h"
#include "../steammath/steammath.h"
#include <string>
#include <iostream>
#include <locale>

using namespace sm;

Parnilogika *Parnilogika::pl = nullptr;

Parnilogika::Parnilogika() {
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

	const std::string oldLocale=std::setlocale(LC_NUMERIC,nullptr);

	std::setlocale(LC_NUMERIC,"C");
	std::string str = std::to_string(f);
	std::setlocale(LC_NUMERIC,oldLocale.c_str());
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);

	for (int i = 0; i < str.length()-1; i++) {
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
	collector.push_back(c);
}

char Parnilogika::popCollector() {
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
	operation = Parnilogika::Operation::UNDEF;
}

std::vector<double> getQuadRoot(double a, double b, double c){
	// TODO we have to figure out how to handle this
	return SteamMath::quadRoot(a, b ,c);
}

double Parnilogika::processResult(double x, double y, Operation operation) {
	switch (operation) {
		case UNDEF:
            return Parnilogika::pl->collectorToDouble();
		case SUM:
			return SteamMath::sum(x, y);
		case SUB:
			return SteamMath::sub(x, y);
		case MUL:
			return SteamMath::mul(x, y);
		case DIV:
			return SteamMath::div(x, y);
		case FACT:
			return SteamMath::fact(x);
		case POW:
			return SteamMath::pow(x, y);
		case ROOT:
			return SteamMath::root(x, y);
		case SIN:
			return SteamMath::sin(x);
		case COS:
			return SteamMath::cos(x);
		case TAN:
			return SteamMath::tan(x);
		case COTAN:
			return SteamMath::cotan(x);
	}
	return 0;
}

std::string Parnilogika::collectorToString(){
    std::string s(collector.begin(), collector.end());
    return s;
}

double Parnilogika::processResult() {
	return Parnilogika::processResult(accumulator, collectorToDouble(), operation);
}

std::string Parnilogika::getDisplayOutput(Operation operation) {
	std::string s;
	s = std::to_string(accumulator);
	char op;
	switch (operation) {
		case UNDEF:
			s = collectorToString();
			return s;
		case SUM:
			s.erase(s.find_last_not_of('0') + 1, std::string::npos);
			if(floor(accumulator) == accumulator){
				s.erase(remove(s.begin(), s.end(), '.'), s.end());
			}
			s += " + " + collectorToString();
			return s;
		case SUB:
			s.erase(s.find_last_not_of('0') + 1, std::string::npos);
			if(floor(accumulator) == accumulator){
				s.erase(remove(s.begin(), s.end(), '.'), s.end());
			}
			s += " - " + collectorToString();
			return s;
		case MUL:
			s.erase(s.find_last_not_of('0') + 1, std::string::npos);
			if(floor(accumulator) == accumulator){
				s.erase(remove(s.begin(), s.end(), '.'), s.end());
			}
			s += " * " + collectorToString();
			return s;
		case DIV:
			s.erase(s.find_last_not_of('0') + 1, std::string::npos);
			if(floor(accumulator) == accumulator){
				s.erase(remove(s.begin(), s.end(), '.'), s.end());
			}
			s += " / " + collectorToString();
			return s;
		case POW:
			s.erase(s.find_last_not_of('0') + 1, std::string::npos);
			if(floor(accumulator) == accumulator){
				s.erase(remove(s.begin(), s.end(), '.'), s.end());
			}
			s += " ^ " + collectorToString();
			return s;
		case ROOT:
			s.erase(s.find_last_not_of('0') + 1, std::string::npos);
			if(floor(accumulator) == accumulator){
				s.erase(remove(s.begin(), s.end(), '.'), s.end());
			}
			s += " √ " + collectorToString();
			return s;
//		case SIN:
//		case COS:
//		case TAN:
//		case COTAN:

	}
}
