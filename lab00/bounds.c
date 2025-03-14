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

    struct bound_data res;
    unsigned int i=0;
    res.exists = false;

    while (i < length) {
        if (value == arr[i]) {
            res.exists = true;
            res.is_upperbound = (true && res.is_upperbound);
            res.is_lowerbound = (true && res.is_lowerbound);
            res.where = i;
        } else if (value > arr[i]) {
            res.is_upperbound = true;
        } else {
            res.is_lowerbound = true;
        }
        ++i;
    }
    

    return res;
}

int main(void) {

    int tam;
    printf("\nIngrese el tamano del arreglo: ");
    scanf("%d", &tam);

    int a[tam];

    int n;
    n=0; //inicializo la varriable 
    while (n<tam) {
        printf("\nIngrese el elemento numero %d del arreglo: \n", n);
        scanf("%d", &a[n]);
        ++n;
    }

    printf("El arreglo es: A[%d]={", tam);
    
    n=0; //reinicio n
    while (n<tam) {
        if(n < tam - 1){
            printf("%d, ", a[n]); //salida con coma
        }else{
            printf("%d", a[n]); // salida sin coma para cerrar el arreglo
        } 
        ++n;
    }
    printf("}\n\n");

    int value;
    printf("\nIngrese el numero que quiere usar: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, tam);

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
            printf("El valor ingresado '%d' es el máximo de la lista\n EL lu");
        } 
        if (result.is_lowerbound) {
            printf("El valor ingresado '%d' es el mínimo de la lista\n");
        }
    } else {  //resultado.exists es falso
        if (result.is_lowerbound) {
            printf("El valor ingresado '%d' es la cota menor\n");
        } 
        if (result.is_upperbound) {
            printf("El valor ingresado '%d' es la cota mayor\n");
        }
    }
    

    return EXIT_SUCCESS;
}

