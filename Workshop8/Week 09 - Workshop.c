
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8


// This is the template ^-^, I will upload the solution in the break

// Define min heap

void upheap(int a[], int x) {
   // Template
    // Choose new position x to put the value original a[x] in
}

void downheap(int a[], int x, int n) {
    // Template
    // Choose new position x to put the value original a[x] in
}

int a[SIZE];


void bottom_up_sort(int a[], int n) {
    // Template
    // Using iteration to sequentially insert new node to heap
    // Using uphead
}

void top_down_sort(int a[], int n) {
    // Template
    // Starting from the first node that has at lease one children (n/2)
    // Then downheap
   
    
}


int main(int argc, char **argv) {
    time_t t;
    srand((unsigned) time(&t));
    
    printf("Original Array: ");
    for(int i = 0; i < SIZE; i++){
        a[i] = rand() % 100;
        printf("%d ",a[i]);
    }
    
    int n = SIZE;
    
    //top_down_sort(a, n);
    //bottom_up_sort(a, n)
    
    // You know you are correct when the two sorting functions produces the same sorted array
    
    return 0;
    
    
}
