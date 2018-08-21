#include <stdio.h>
#include <stdlib.h>



void printA(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    
    
    int *a = (int*) malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
        a[i] = rand();
    
    //printf("%lu\n", a);
    
    printA(a, n);
    
    
    //printf("%d\n", *a);
    
    int m;
//
    printf("Please enter the number of additional integers: ");
    scanf("%d", &m);
//
    a = (int*) realloc(a, (n + m)  * sizeof(int));
//
    for (int i = n; i < n + m; i++)
        a[i] = rand();
//
//
    printA(a, n + m);
    
    
    free(a);
    
    
    return 0;
    
    
}
