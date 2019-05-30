#include "big_num.h"
#include "math_utils.h"

int* split(int digit) {
    int* res = malloc(3 * sizeof(int));
    for (int i = 0; i < digit_size; i++) {
        res[i] = (digit / powi(10, i)) % 10;
    }
    return res;
}

big_num mul(big_num a, big_num b) {
    big_num res = create_empty(a.size + b.size);

    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < b.size; j++) {
            int* split_a = split(a.digits[i]);
            int* split_b = split(b.digits[j]);
            big_num res_digit = create_empty(2);
            for (int k = 0; k < digit_size; k++) {
                for (int l = 0; l < digit_size; l++) {
                    res_digit = add(res_digit, create(split_a[k] * split_b[l] * powi(10, k + l))); //from_string(to_string
                }
            }
            res = add(res, shift(res_digit, digit_size * (i + j))); //from_string(to_string
        }
    }

    return res;
}
