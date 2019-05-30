#include "big_num.h"

int compare(big_num a, big_num b) {
    if (a.size < b.size)
        return -1;
    else if (a.size > b.size)
        return 1;
    else
        for (int i = a.size - 1; i >= 0; i--) {
            if (a.digits[i] < b.digits[i])
                return -1;
            else if (a.digits[i] > b.digits[i])
                return 1;
        }
    return 0;
}

