#include "big_num.h"
#include "math_utils.h"
#include "error.h"
#include <string.h>

char* cut(char* str, int from, int to) {
    char* res = calloc(to - from + 2, sizeof(char));

    for (int i = from; i <= to && str[i] != 0; i++) {
        res[i - from] = str[i];
    }
    res[to + 1] = 0;

    return res;
}

division div_close(big_num a, big_num b) {
    int quotient = 0;
    big_num remainder = a;
    while (compare(b, remainder) <= 0) {
        quotient++;
        if (quotient > 9) {
            ERROR("too big difference in numbers");
        }
        remainder = sub(remainder, b);
    }
    division res = {create(quotient), remainder};
    return res;
}

division div_euc(big_num a, big_num b) {
    if (compare(b, create(0)) == 0) {
        ERROR("attempt to divide by 0");
    }
    char* str_a = to_string(a);
    char* str_b = to_string(b);
    int str_a_len = strlen(str_a);
    int str_b_len = strlen(str_b);

    big_num quotient = create(0);
    big_num remainder = a;

    int j = str_a_len - str_b_len + 1;
    while (j > 0 || ( j == 0 && compare(from_string(str_a), from_string(str_b)) >= 0 )) {
        char* cut_str_a_1 = cut(str_a, 0, strlen(str_a) - j);
        char* cut_str_a_2 = cut(str_a, strlen(str_a) - j + 1, strlen(str_a));

        division div_u = div_close(from_string(cut_str_a_1), b);
        quotient = add(shift(quotient, 1), div_u.quotient);
        remainder = div_u.remainder;

        memset(str_a, 0, (size_t) str_a_len);
        strcpy(str_a, to_string(remainder));
        strcat(str_a, cut_str_a_2);
        j--;

        free(cut_str_a_1);
        free(cut_str_a_2);
    }

    free(str_a);
    free(str_b);

    division res = {quotient, remainder};
    return res;
}