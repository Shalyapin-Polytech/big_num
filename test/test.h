#ifndef _TEST_H
#define _TEST_H

#include "big_num.h"
#include <stdio.h>

#define FAIL(format) \
    fprintf(stderr, "error: expected" format ", but got " format ".", a, b); \
    abort();

void assert_strings_equals(char* a, char* b) {
    if (strcmp(a, b) != 0)
        FAIL("%s");
}

void assert_int_equals(int a, int b) {
    if (a != b)
        FAIL("%d");
}

void assert_int_array_equals(int* a, int* b, size_t size) {
    for (int i = 0; i < size; i++) {
        assert_int_equals(a[i], b[i]);
    }
}

void assert_big_nums_equals(big_num a, big_num b) {
    assert_int_equals(a.size, b.size);
    assert_int_array_equals(a.digits, b.digits, a.size);
}

#undef FAIL

void test();

int main() {
    test();
    printf("Success!\n");
    return 0;
}

#endif
