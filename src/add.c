#include "big_num.h"
#include "math_utils.h"

big_num add(big_num a, big_num b) {
    big_num max = compare(a, b) > 0 ? a : b;
    big_num min = compare(a, b) <= 0 ? a : b;
    big_num res = create_empty(max.size + 1);

    for (int i = 0; i < max.size; i++) {
        int digits_sum = res.digits[i] + max.digits[i] + ( i < min.size ? min.digits[i] : 0 );
        if (digits_sum < powi(10, digit_size))
            put(&res, i, digits_sum);
        else {
            put(&res, i, digits_sum - powi(10, digit_size));
            put(&res, i + 1, 1);
        }
    }

    return res;
}