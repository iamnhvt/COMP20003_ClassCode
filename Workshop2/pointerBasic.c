#include <stdio.h>

int main() {
    int p = 700;
    int *pc;
    pc = &p;
    
    printf("%lu\n", pc); 700
    
    printf("%lu\n", &p); address
    
    printf("%d\n", *pc); 700
}
