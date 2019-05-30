#include <stdio.h>
#include "big_num.h"

char* to_string(big_num num) {
    char* str = malloc((num.size + 1) * sizeof(char));
    int n = 0;

    for (int num_i = num.size - 1; num_i >= 0; num_i--) {
        n += sprintf(&str[n], num_i < num.size - 1 ? "%03d" : "%d", num.digits[num_i]);
    }
    return str;
}