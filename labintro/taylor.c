#include <stdio.h>
#include <math.h>

int main() {
    // Definir la tolerancia de error
    double tolerancia = 1e-10;

    // Definir el valor de x
    double x = 0.5;

    // Encontrar el menor k que satisface la desigualdad
    int k = 1;
    while (pow(x, k + 1) / (k + 1) >= tolerancia) {
        k++;
    }

    // Imprimir el resultado
    printf("El menor k que satisface la desigualdad es: %d\n", k);
    
    return 0;
}