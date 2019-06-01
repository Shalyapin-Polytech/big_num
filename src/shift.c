#include "big_num.h"
#include "math_utils.h"

big_num shift(big_num num, int exp) {
    int from = exp / digit_size;
    int transfer_size = exp % digit_size;
    big_num res = create_empty(num.size + ceil_div(exp, digit_size));

    for (int i = 0; i < from; i++) {
        put(&res, i, 0);
    }
    for (int i = from; i < res.released_size; i++) {
        put(&res, i, res.digits[i] + num.digits[i - from] % ( powi(10, digit_size - transfer_size) ) * powi(10, transfer_size));
        put(&res, i + 1, num.digits[i - from] / powi(10, digit_size - transfer_size));
    }

    return res;
}
