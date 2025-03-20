#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h> // busque en google como hacer para leer caracteres especiales como ñ

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res = {false, false, false, 0};
    

    unsigned int i;
    
    int min = arr[0];
    int max = arr[0];
    
    for (i = 0; i < length; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        if (value == arr[i]) {
            res.exists = true;
            res.where = i;
        }
    }

    res.is_upperbound = (value >= max);
    res.is_lowerbound = (value <= min);

    return res;
}

int main(void) {
    setlocale(LC_ALL, "es_ES.UTF-8"); //  como hacer para leer caracteres especiales como ñ

    int tam;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d", &tam);

    if (tam <= 0) {
        printf("Error: El tamaño del arreglo debe ser mayor que 0.\n");
        return EXIT_FAILURE;
    }

    int a[tam];
    for (int n = 0; n < tam; ++n) {
        printf("Ingrese el elemento numero %d del arreglo: ", n);
        scanf("%d", &a[n]);
    }

    printf("El arreglo es: A[%d] = {", tam);
    for (int n = 0; n < tam; ++n) {
        printf("%d%s", a[n], (n < tam - 1) ? ", " : "");
    }
    printf("}\n\n");

    int value;
    printf("Ingrese el numero que quiere usar: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, tam);
    
    if (result.exists) {
        printf("El valor ingresado '%d' existe en la lista en la posición %d, y ", value, result.where); //lo primero es imprimir el lugar si es que esta
        if (result.is_upperbound) {
            printf("es el máximo de la lista.\n");
        } else if (result.is_lowerbound) {
            printf("es el mínimo de la lista.\n");
        }
        if (result.is_upperbound == false && result.is_lowerbound == false) {
            printf("el valor no es máximo ni mínimo.\n");
        }
    } else {
        if (result.is_lowerbound) {
            printf("El valor ingresado '%d' es cota menor (no está en el arreglo).\n", value);
        } else if (result.is_upperbound) {
            printf("El valor ingresado '%d' es cota mayor (no está en el arreglo).\n", value);
        } else {
            printf("El valor ingresado '%d' no existe en la lista.\n", value);
        }
    }

    return EXIT_SUCCESS;
}