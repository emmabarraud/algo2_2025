#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x >= 0) {
        *y = x;
    } else {
        *y =-x;
    } 
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---
    a=-10;

    absolute(a,&res);
    printf("Resultado delvalor absoluto: %d\n", res);
   
    assert(res >= 0 && (res == a || res == -a));

    return EXIT_SUCCESS;
}


// el parametro int *y es de tipo out porque modifica el valor de y (que afecta a la variable original, en este caso res).

