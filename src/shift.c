#include "big_num.h"
#include "math_utils.h"
#include <string.h>

big_num shift(big_num num, int exp) {
    char* str_num = to_string(num);
    char* zeros = calloc(exp + 1, sizeof(char));

    for (int i = 0; i < exp; i++) {
        zeros[i] = '0';
    }
    strcat(str_num, zeros);

    return from_string(str_num);
}
