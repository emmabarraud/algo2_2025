#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"
#include <assert.h>

/*bool tiene_cima(int a[], int n) {
    if (n == 1) {
        // Un arreglo de un solo elemento siempre tiene una cima
        return true;
    }

    int k = 1;

    // Buscar el punto de incremento
    while (k < n && a[k - 1] < a[k]) {
        k++;
    }

    // Si no hay un incremento o el arreglo es estrictamente creciente o decreciente
    // Entonces no tiene una cima
    if (k == 1 || k == n) {
        return false;
    }

    // Buscar el punto de decremento
    while (k < n && a[k - 1] > a[k]) {
        k++;
    }

    // Si hemos llegado al final, entonces hemos encontrado una cima
    return k == n;
}
*/

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
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

// Función auxiliar recursiva

int cima_rec(int a[], int lft, int rgt) {
    int k = 0;
    int mid;
    if (lft == rgt) { // es equiv a decir que length es =1
        //printf("Cima encontrada en posición %d\n", lft);
        k = lft;

    } else {
        mid = (lft + rgt) / 2; //División del Problema (Búsqueda Binaria): Si el arreglo tiene más de un elemento, la función calcula el índice medio (mid):
        //printf("lft=%d, mid=%d, rgt=%d, a[mid]=%d, a[mid+1]=%d\n", lft, mid, rgt, a[mid], a[mid + 1]); 
        if (a[mid] < a[mid + 1] && (mid + 1 <= rgt)) {
                k = cima_rec(a, mid + 1, rgt);
        } else if (mid - 1 >= lft) {
                k = cima_rec(a, lft, mid);
        }
    }
    return k; 
}

/*Condición para la Recursión:

Si el valor en la posición mid es menor que el valor en la posición mid + 1, significa que estamos en una parte ascendente del arreglo, por lo que el pico debe estar a la derecha. Entonces, la función hace una llamada recursiva con el intervalo ajustado a la mitad derecha (mid + 1 a rgt):


if (a[mid] < a[mid + 1] && (mid + 1 <= rgt)) {
    k = cima_rec(a, mid + 1, rgt);
}


Si el valor en la posición mid no es menor que el valor en la posición mid + 1, entonces el pico podría estar a la izquierda, y la función hace una llamada recursiva con el intervalo ajustado a la mitad izquierda (lft a mid):
else if (mid - 1 >= lft) {
    k = cima_rec(a, lft, mid);
}
    */

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y vencerás.
 *
 * PRECONDICIÓN: tiene_cima(a, length)
 */
int cima_log(int a[], int length) {
    int cima;
//assert(tiene_cima(a,length));
        cima = cima_rec(a, 0, length - 1);
    return cima;
}


