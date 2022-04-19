#include "steammath.h"
// FIXME not sure if its ok that we are using this.
// I currently use it for abs and sqrt. Not sure if its cool tho.
// I could replace the abs if I wanted to but sqrt is a different couple of coffee.
#include <math.h>
#include <iostream>
#include <cfenv>

using namespace sm;


int SteamMath::include_test(int one) {
    if (one > 0 && one < 2) {
        return (one * 1000) * (one - 1) + 1;
    }
    return 2;
}

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
        throw PositiveNonZeroNumberRequired("x has to be greater then zero");
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
    if (x < 1) {
        throw PositiveNonZeroNumberRequired("y has to be greater then zero");
    }
    std::feclearexcept(FE_ALL_EXCEPT);

    double result = x;
    for (int i = 0; i < y-1; i++) {
        result *= x;
    }

    SteamMath::calcErrorCheck();
    return result;
}

double SteamMath::root(double x, double y) {
    std::feclearexcept(FE_ALL_EXCEPT);

    // FIXME Only works as a square root.
    double result = sqrt(x);

    // FIXME division seems to set off some unexpexted flags.
    //SteamMath::calcErrorCheck();
    //SteamMath::calcErrorCheck();
    return result;
}

SmException::SmException(char *message) {
    std::cout << message << std::endl;
}
