#include "steammath.h"

int SteamMath::include_test(int one) {
    if (one > 0 && one < 2) {
        return (one * 1000) * (one - 1) + 1;
    }
    return 2;
}
