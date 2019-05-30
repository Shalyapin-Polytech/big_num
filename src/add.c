#include "big_num.h"
#include "math_utils.h"

big_num add(big_num a, big_num b) {
    int max_size = compare(a, b) > 0 ? a.size : b.size;
    big_num res = create_empty(max_size + 1);

    for (int i = 0; i < max_size; i++) {
        put(&res, i, res.digits[i] + a.digits[i] + b.digits[i]);
        if (res.digits[i] >= powi(10, digit_size)) {
            put(&res, i + 1, res.digits[i + 1] + 1);
            put(&res, i, res.digits[i] - powi(10, digit_size));
        }
    }

    return res;
}