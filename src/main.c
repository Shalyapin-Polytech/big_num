#include "big_num.h"
//#include "math_utils.h"
#include <stdio.h>

int powi(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int ceil_div(int a, int b) {
    return a % b > 0 ? a / b + 1 : a / b;
}

int main() {
    char file_names[256];
    scanf("%s", file_names);

    char* sep = " ";
    char* input_file_name = strtok(file_names, sep);
    char* output_file_name = strtok(NULL, sep);

    FILE* input_file = fopen(input_file_name, "r");
    char input[256];
    fgets(input, 256, input_file);

    fclose(input_file);

    char* command = strtok(input, sep);
    char* a = strtok(NULL, sep);
    big_num b = from_string(strtok(NULL, sep));

//    big_num res = create_empty(a.size + b.size);

//    if (strcmp(command, "add"))
//        res = add(a, b);
//    else if (strcmp(command, "sub"))
//        res = sub(a, b);
//    else if (strcmp(command, "mul"))
//        res = mul(a, b);
//    else if (strcmp(command, "div"))
//        res = div_euc(a, b).quotient;
//    else if (strcmp(command, "mod"))
//        res = div_euc(a, b).remainder;

//    FILE* tst = fopen("t.txt", "w");
//    fprintf(tst, output_file_name);
//    fclose(tst);

//    char* i = "0";
//    if (to_string(from_string("12345").size == 2)
//        i = "1";

    big_num test = create_empty(3);
    put(&test, 0, 123);
    put(&test, 1, 45);
    put(&test, 2, 9);
    big_num num = create_empty(1);
    put(&num, 0, 12);

    int exp = 5;

    int from = exp / digit_size; //=1
    int transfer_size = exp % digit_size;
    big_num res = create_empty(2);
//
//    for (int i = 0; i < from; i++) {
//        put(&res, i, 0);
//    }
//    for (int i = 1; i < ( 3 - 1 ); i++) {
        put(&res, 1, num.digits[0]);
//    }

//    int a_it[5]={5,21,456,1,3};
//    big_num bn = create_empty(2);
//    put(bn, 0, )
//    char s[9] = {0};
//    int n = 0;
//
//    for (int i = 4; i >= 0; i--) {
//        n += sprintf (&s[n], "%d", a_it[i]);
//    }

//    sprintf(tst, "%d", from_string("12345\0").digits[0]);
//    sprintf(tst, "%d", from_string("12345678").digits[1]);

    FILE* output_file = fopen("t.txt", "w");
    fprintf(output_file, to_string(res));
    fclose(output_file);

//    char tst[256] = "test teds";
//    char* one = strtok(tst, " ");
////    char* two = tst;
////    scanf("%s", tst);
//    FILE* input_file = fopen("t.txt", "w");
//    fprintf(input_file, one);
//    fclose(input_file);

    return 0;
}

