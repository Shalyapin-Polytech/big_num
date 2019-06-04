#ifndef ERROR_H
#define ERROR_H

#include <stdlib.h>
#include <stdio.h>

#define ERROR(msg) \
    printf("error at %s:%d in function %s: %s\n", __FILE__, __LINE__, __func__, msg); \
    exit(-1);

#endif
