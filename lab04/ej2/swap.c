#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux; 
}

int main() {
  int x, y;
  x = 6;
  y = 4;
  printf("x: %d, y: %d\n",x, y);
  swap(&x, &y);
  printf("Swapping x e y:\nx: %d, y: %d\n", x, y);
  //r := 0
  //  {- esta última asignación es análoga a `return EXIT_SUCCESS;` -}
  return EXIT_SUCCESS;
}
