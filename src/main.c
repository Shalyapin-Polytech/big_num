#include "big_num.h"
#include <stdio.h>

int main() {
    char input_file_name[256], output_file_name[256];
    scanf("%s %s", input_file_name, output_file_name);

    FILE* input_file = fopen(input_file_name, "r");
    char input[256];
    fgets(input, 256, input_file);
    fclose(input_file);

    char* sep = " ";
    char* command = strtok(input, sep);
    big_num a = from_string(strtok(NULL, sep));
    big_num b = from_string(strtok(NULL, sep));

    big_num res = create_empty(a.size + b.size);

    if (strcmp(command, "add") == 0)
        res = add(a, b);
    else if (strcmp(command, "sub") == 0)
        res = sub(a, b);
    else if (strcmp(command, "mul") == 0)
        res = mul(a, b);
    else if (strcmp(command, "div") == 0)
        res = div_euc(a, b).quotient;
    else if (strcmp(command, "mod") == 0)
        res = div_euc(a, b).remainder;

    FILE* output_file = fopen(output_file_name, "w");
    fprintf(output_file, to_string(res));
    fclose(output_file);

    return 0;
}

