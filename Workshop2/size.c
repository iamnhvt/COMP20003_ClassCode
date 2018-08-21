#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main() {
    printf("int: %lu\n", sizeof(int)); //4
    printf("char: %lu\n", sizeof(char));// 1
    printf("double: %lu\n", sizeof(double));// 8
    printf("float: %lu\n", sizeof(float)); //?
    printf("pointer int: %lu\n", sizeof(int *)); //4
    printf("pointer double: %lu\n", sizeof(double *)); //4

    return 0;
}
