#include "big_num.h"

big_num create_empty(int released_size) {
    big_num obj = {
            .digits = malloc(digit_size * released_size * sizeof(int)),
            .released_size = released_size,
            .size = 1
    };
    return obj;
}

void put(big_num* num, int to, int what) {
    if (to >= num->released_size)
        return;
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
    big_num obj = create_empty(i < 1000 ? 1 : 2);
    put(&obj, 0, i % 1000);
    if (i >= 1000)
        put(&obj, 1, i / 1000);
    return obj;
}
