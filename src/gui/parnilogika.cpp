#include "parnilogika.h"
#include <string>
#include <iostream>
#include <locale>

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
	erraseCollector();

	const std::string oldLocale=std::setlocale(LC_NUMERIC,nullptr);

	std::setlocale(LC_NUMERIC,"C");
	std::string str = std::to_string(f);
	std::setlocale(LC_NUMERIC,oldLocale.c_str());
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);

	for (int i = 0; (size_t) i < str.length()-1; i++) {
		appendToCollector(str[i]);
	}

}

void Parnilogika::erraseCollector() {
	// FIXME I dont think i need to call a destructor on the old collector
	// because I didnt use "new" to create it, but I am not sure.
	// I dont know how magical this steammachine of a language is...
	collector = std::vector<char>();
}

void Parnilogika::appendToCollector(char c) {
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

double Parnilogika::processResult(double x, double y, Operation operation) {
	// TODO implement.
	(void)x, (void)y, (void)operation;
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

double Parnilogika::processResult() {
	return Parnilogika::processResult(accumulator, collectorToDouble(), operation);
}
