#ifndef BIG_NUM_H
#define BIG_NUM_H

#include <stdlib.h>
#include <string.h>

#define digit_size 3

typedef struct big_num_struct {
    int* digits;
    int released_size;
    int size;
} big_num;

typedef struct division {
    big_num quotient;
    big_num remainder;
} division;


big_num create_empty(int released_size);
void put(big_num* num, int to, int what);
big_num create(int i);

int compare(big_num a, big_num b);
big_num shift(big_num num, int exp);
big_num add(big_num a, big_num b);
big_num sub(big_num a, big_num b);
big_num mul(big_num a, big_num b);
division div_euc(big_num a, big_num b);
big_num from_string(char* str);
char* to_string(big_num num);

#endif