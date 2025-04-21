#include <stdio.h>
#include <stdlib.h>
#include "cima_log.h"

int main(void) {
    int a[] = {-2, 8, 9, 5, 0};
    int length = 5;
    int result;

    printf("Arreglo: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    result = cima_log(a, length);

    printf("Cima en posición: %i (valor: %i)\n", result, a[result]);

    return EXIT_SUCCESS;
}
