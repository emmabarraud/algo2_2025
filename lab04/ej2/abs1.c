#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0) {
        y = x;
    } else {
        y =-x;
    } 
}

int main(void) {
    int res;
    int a = -10;
    absolute(a,res);
    printf("Resultado delvalor absoluto: %d\n", res);

    return EXIT_SUCCESS;
}

// el valor que se muestra por pantalla es 0, a diferencia de el programa del lenguaje del teorico, en el que deberia dar 10 osea el valor absoluto de -10.
