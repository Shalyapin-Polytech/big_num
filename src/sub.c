#include "big_num.h"
#include "math_utils.h"

big_num sub(big_num a, big_num b) {
    big_num minuend = compare(a, b) >= 0 ? a : b; // уменьшаемое
    big_num subtrahend = compare(a, b) < 0 ? a : b; // вычитаемое
    big_num res = create_empty(minuend.size);

    for (int i = 0; i < minuend.size; i++) {
        if (minuend.digits[i] < subtrahend.digits[i]) {
            put(&minuend, i + 1, minuend.digits[i + 1] - 1);
            put(&minuend, i, minuend.digits[i] + powi(10, digit_size));
        }
        put(&res, i, minuend.digits[i] - subtrahend.digits[i]);
    }

    return res;
}

