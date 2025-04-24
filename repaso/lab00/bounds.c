#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    res.exists = false;
    res.is_lowerbound = false;
    res.is_lowerbound = false;
    res.where = 0;

    unsigned int i = 0;
    while( i < length) {
        if (arr[i] <= value) {
            res.is_upperbound = true;
        } else if (arr[i] >= value) {
            res.is_lowerbound = true;
        }

        if(arr[i] == value) {
            res.exists = true;
            res.where= i;
        }
    i++;    
    }
    
    return res;
}

int main(void) {
    int tam;
    printf("Ingresa el tamaño de tu arreglo:\n");
    scanf("%d", &tam);

    if (tam > 4 || tam <= 0) {
        printf ("ERROR; el arreglo tiene que ser de tamaño menor o igual a 4\n");
        exit(EXIT_FAILURE);
    }

    int a[tam];
    int value;

        int i = 0;
        while (i < tam) {
        printf("Valor %d :", i);
        scanf("%d", &a[i]);
        i++;
        }   

    printf("Los valores ingresados son:\n");
    i = 0;
    while (i< tam) {
        printf("%d ", a[i]);
        i++;
    }

    printf("\ningrese el valor a comparar:\n");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);
    unsigned int donde = result.where;
    if(result.is_upperbound) {
        printf ("\nEl valor ingresado es mayor o igual a todos los elementos del arreglo\n");
    } else if (result.is_lowerbound) {
            printf ("\nEl valor ingresado es menor o igual a todos los elementos del arreglo\n");
        }
    if (result.exists) {
        printf ("\nEl resultado existe y se encuentra en la posicion %u\n", donde);
    } else {
        printf("Pero este no existe\n");
    }

}