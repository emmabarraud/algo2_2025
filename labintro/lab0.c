#include <stdio.h>
#include <math.h>

#define MAX_N 100  // Máximo número de términos en la sucesión

// Función para calcular el orden de convergencia
double calcular_orden_convergencia(double x[], int n, double L) {
    double num, den, p_total = 0.0;
    int contador = 0;

    for (int i = 1; i < n - 1; i++) {
        double err_n   = fabs(x[i] - L);
        double err_np1 = fabs(x[i + 1] - L);

        if (err_n > 0 && err_np1 > 0) {
            num = log(err_np1);
            den = log(err_n);
            double p = num / den;
            p_total += p;
            contador++;
        }
    }

    return (contador > 0) ? (p_total / contador) : 0.0;
}

int main() {
    double x[MAX_N];
    int n;
    double L;

    // Leer la cantidad de términos de la sucesión
    printf("Ingrese el número de términos de la sucesión (máx %d): ", MAX_N);
    scanf("%d", &n);
    if (n < 2 || n > MAX_N) {
        printf("Número de términos inválido.\n");
        return 1;
    }

    // Leer la sucesión
    printf("Ingrese los %d términos de la sucesión:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    // Leer el valor de L
    printf("Ingrese el valor estimado del límite L: ");
    scanf("%lf", &L);

    // Calcular y mostrar la velocidad de convergencia
    double p = calcular_orden_convergencia(x, n, L);
    printf("Orden de convergencia aproximado: %.5f\n", p);

    return 0;
}