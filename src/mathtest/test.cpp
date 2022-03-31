#include <iostream>
#include "steammath.h"
#include <string>

int main() {
    std::cout << "This is a main for mathlib tests! " << std::to_string(SteamMath::include_test(1)) << std::endl;
    return 0;
}
