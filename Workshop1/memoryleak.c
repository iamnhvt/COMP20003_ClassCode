#include <stdio.h>
#include <stdlib.h>


const int ARR_SIZE = 1000;

int main() {
    int *intArr = malloc(sizeof(int) * ARR_SIZE);
    
    for (int i = 0; i < ARR_SIZE; i++)
        intArr[i] = 2;
    
    
    
    
    return 0;
}
