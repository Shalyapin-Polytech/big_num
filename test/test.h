#ifndef _TEST_H
#define _TEST_H

#include "error.h"
#include <stdio.h>
#include <string.h>

void _assert_strings_equals(char* a, char* b, int line) {
    if (strcmp(a, b) != 0) {
        printf("at line %d: expected %s, but got %s\n", line, a, b);
        ERROR("test failed");
    }
}

void _assert_int_equals(int a, int b, int line) {
    if (a != b) {
        printf("at line %d: expected %d, but got %d\n", line, a, b);
        ERROR("test failed");
    }
}

void _assert_int_array_equals(int* a, int* b, int size, int line) {
    for (int i = 0; i < size; i++) {
        _assert_int_equals(a[i], b[i], line);
    }
}

#define assert_strings_equals(a, b) _assert_strings_equals(a, b, __LINE__)
#define assert_int_equals(a, b) _assert_int_equals(a, b, __LINE__)
#define assert_int_array_equals(a, b, size) _assert_int_array_equals(a, b, size, __LINE__)
#define assert_big_nums_equals(a, b) \
    _assert_int_equals(a.size, b.size, __LINE__); \
    _assert_int_array_equals(a.digits, b.digits, a.size, __LINE__);

void test();

int main() {
    test();
    printf("All tests passed!\n");
    return 0;
}

#endif
