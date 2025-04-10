#include <stdio.h>
#include <math.h>

// Función merge para intercalar dos segmentos ordenados del arreglo
void merge(int a[], int lft, int mid, int rgt) {
    int n = rgt - lft + 1;
    int tmp[n];  // arreglo temporal del tamaño del segmento que se va a mezclar
    int i;

    // Copiamos el primer segmento (izquierdo) al arreglo temporal
    for (i = lft; i <= mid; i++) {
        tmp[i - lft] = a[i];
    }

    int j = 0;              // índice en tmp (segmento izquierdo)
    int k = mid + 1;        // índice en segmento derecho (en a[])
    int idx = lft;          // índice actual en a[] donde vamos escribiendo el resultado

    // Mezclamos los dos segmentos ordenados en a[]
    while (j <= mid - lft && k <= rgt) {
        if (tmp[j] <= a[k]) {
            a[idx++] = tmp[j++];
        } else {
            a[idx++] = a[k++];
        }
    }

    // Si quedó algo del segmento izquierdo en tmp, lo copiamos
    while (j <= mid - lft) {
        a[idx++] = tmp[j++];
    }
}

// Procedimiento principal: intercala cada par de segmentos ordenados de tamaño 2^i
void intercalarCada(int a[], int n, int i) {
    int tamSegmento = 1 << i;  // tamSegmento = 2^i, usando desplazamiento de bits
    int j = 0;

    // Mientras no nos pasemos del arreglo, seguimos procesando pares de segmentos
    while (2 * j * tamSegmento + 1 <= 2 * n) {
        int lft = 2 * j * tamSegmento;                    // inicio del primer segmento
        int mid = lft + tamSegmento - 1;                  // fin del primer segmento
        int rgt = mid + tamSegmento;                      // fin del segundo segmento

        merge(a, lft, mid, rgt);  // intercalamos los dos segmentos ordenados
        j++;
    }
}

// Función auxiliar para imprimir el arreglo
void imprimirArreglo(int a[], int n) {
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Ejemplo de uso
int main() {
    int a[] = {3, 7, 1, 6, 1, 5, 3, 4};  // arreglo de 2n elementos
    int n = 4;  // la mitad del tamaño del arreglo (2n = 8)

    printf("Arreglo original:\n");
    imprimirArreglo(a, n);

    // Intercalamos con i = 1
    intercalarCada(a, n, 1);
    printf("Después de intercalar con i = 1:\n");
    imprimirArreglo(a, n);

    // Intercalamos nuevamente con i = 2
    intercalarCada(a, n, 2);
    printf("Después de intercalar con i = 2:\n");
    imprimirArreglo(a, n);

    return 0;
}
