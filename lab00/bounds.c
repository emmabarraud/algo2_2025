#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {

    struct bound_data res = {false, false, false, 0}; // inicializo todas las variables en false

    unsigned int i = 0; //variables auxiliares
    int min = arr[0]; // empiezo en el primer elemento del arreglo
    int max = arr[0]; 

    while (i < length) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }

        if (value == arr[i]) {
            res.exists = true;
            res.where = i;
        }
        ++i;
    }

    res.is_upperbound = (value >= max); // asigno valores de verdad, comparo el valor dado con el valor calculado en el while
    res.is_lowerbound = (value <= min);

    return res;
}
int main(void) {

    int tam;
    printf("\nIngrese el tamano del arreglo: ");
    scanf("%d", &tam);

    int a[tam];

    int n=0;
    while (n<tam) {
        printf("\nIngrese el elemento numero %d del arreglo: \n", n);
        scanf("%d", &a[n]);
        ++n;
    }

    printf("El arreglo es: A[%d]={", tam);
    
    n=0;
    while (n<tam) {
        if(n < tam - 1){
            printf("%d, ", a[n]);
        }else{
            printf("%d", a[n]); 
        }
        ++n;
    }
    printf("}\n\n");

    int value;
    printf("\nIngrese el numero que quiere usar: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, tam);
    int lugar = result.where;
/*    if ((result.exists == true) && (result.is_upperbound == true)) {
        printf("El valor ingresado '%d' es el maximo de la lista\n");
     };
    if ((result.exists == true) && (result.is_lowerbound == true)) {
        printf ("El valor ingresado '%d' es el maximo de la lista\n");
    };
    if (result.is_lowerbound == true && result.exists == false) {
        printf ("El valor ingresado '%d' es la cota menor\n");
    };
    if (result.is_upperbound == true && result.exists == false) {
        printf ("El valor ingresado '%d' es la cota mayor\n");
    };
MAS OPTIMIZADO
*/


    if (result.exists) { //resultado.exists es verdadero
        if (result.is_upperbound) {
            printf("El valor ingresado '%d' es el máximo de la lista\n El lugar en el que se encuentra es %d", value, lugar);
        } 
        if (result.is_lowerbound) {
            printf("El valor ingresado '%d' es el mínimo de la lista\n El lugar en el que se encuentra es %d", value, lugar);
        }
    } else {  //resultado.exists es falso
        if (result.is_lowerbound) {
            printf("El valor ingresado '%d' es la cota menor (no esta en el arreglo)\n", value);
        } 
        if (result.is_upperbound) {
            printf("El valor ingresado '%d' es la cota mayor (no esta en el arreglo)\n", value);
        }
    }
    

    return EXIT_SUCCESS;
}

