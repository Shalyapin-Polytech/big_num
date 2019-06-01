#include "big_num.h"
#include "math_utils.h"
#include "error.h"

big_num create_empty(int released_size) {
    big_num obj = {
            .digits = calloc(digit_size * released_size, sizeof(int)),
            .released_size = released_size,
            .size = 1
    };
    return obj;
}

void put(big_num* num, int to, int what) {
    if (to >= num->released_size) {
        printf("attempt to put %d to %d\n", what, to);
        error("not enough allocated memory");
    }
    num->digits[to] = what;
    if (what == 0) {
        if (to == num->size - 1) {
            while (num->digits[num->size - 1] == 0 && num->size > 1) {
                num->size--;
            }
        }
    } else {
        if (to >= num->size)
            num->size = to + 1;
    }
}

big_num create(int i) {
    if (i >= powi(10, digit_size)) {
        error("attempt to put too big integer");
    }
    big_num obj = create_empty(1);
    put(&obj, 0, i);
    return obj;
}
