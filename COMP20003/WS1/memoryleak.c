#include <stdio.h>


int main() {
  char * x = malloc(10 * sizeof(char));



  free(x);

  return 0;

}
