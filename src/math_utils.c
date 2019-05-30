#include "math_utils.h"

int powi(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int ceil_div(int a, int b) {
    return a % b > 0 ? a / b + 1 : a / b;
}
