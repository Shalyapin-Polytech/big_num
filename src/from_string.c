#include "big_num.h"
#include "math_utils.h"

big_num from_string(char* str) {
    big_num num = create_empty(ceil_div(strlen(str), digit_size));
    int num_i = 0;

    for (int str_i = strlen(str) - 1; str_i >= 0; str_i -= digit_size) {
        for (int digit_i = 0; digit_i < digit_size && str_i - digit_i >= 0; digit_i++) {
            put(&num, num_i, num.digits[num_i] + ( ( str[str_i - digit_i] - '0' ) * powi(10, digit_i) ));
        }
        num_i++;
    }
    return num;
}
