#include <stdio.h>

int main() {
    int a[3][4] = {1,2,3,4,7,8,9,10,11,12,13,14};
    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%2d ", a[i][j]);
        printf("\n");
    }
    
    printf("\n");
    printf("%d\n", a[1][2]);
    
    printf("%d\n", *(* (a + 1) + 2));
    
    
    return 0;
}
