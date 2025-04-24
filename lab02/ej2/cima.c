#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int n) {
    int k = 1;
    bool result = false;  

    while (k < n && a[k - 1] < a[k]) {
        k++;
    }

    if (k == 1 || k == n) {
        result = false; 
    } else {
        while (k < n && a[k - 1] > a[k]) {
            k++;
        }

        if (k == n) {
            result = true; 
        } else {
            result = false; 
        }
    }
    // Si el arreglo tiene un solo elemento, se considera que tiene cima
    // porque no hay elementos para comparar.
    // Por lo tanto, la cima es el único elemento.
    if (n == 1) {result = true;};

    return result;  
}
/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima(int a[], int length) {
    int cima = 0;
    if (tiene_cima(a,length) == false) {
        cima = -1;
    } else {
        assert(tiene_cima(a,length));
        int k = 1;

        while ( k < length && a[k-1] < a[k]) {
            k++;
        }
        
        cima = k-1;
    }


    return cima;
}
