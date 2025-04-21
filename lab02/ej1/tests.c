#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

#define MAX_LENGTH 5
#define N_TESTCASES 10

struct testcase {
    int a[MAX_LENGTH];
    int length;
    int k;
    int result;
};

int main() {
    struct testcase tests[N_TESTCASES] = {
        // Caso 1: arreglo de un elemento, k=0
        { {8}, 1, 0, 8 },

        // Caso 2: arreglo de dos elementos ordenados, k=0
        { {1, 2}, 2, 0, 1 },

        // Caso 3: arreglo de dos elementos ordenados, k=1
        { {1, 2}, 2, 1, 2 },

        // Caso 4: arreglo de dos elementos desordenados, k=0
        { {2, 1}, 2, 0, 1 },

        // Caso 5: arreglo de dos elementos desordenados, k=1
        { {2, 1}, 2, 1, 2 },

        // Caso 6: arreglo de ejemplo dado {8, -2, 9, 0, 13} con k=0
        { {8, -2, 9, 0, 13}, 5, 0, -2 },

        // Caso 7: arreglo de ejemplo dado {8, -2, 9, 0, 13} con k=1
        { {8, -2, 9, 0, 13}, 5, 1, 0 },

        // Caso 8: arreglo de ejemplo dado {8, -2, 9, 0, 13} con k=2
        { {8, -2, 9, 0, 13}, 5, 2, 8 },

        // Caso 9: arreglo de ejemplo dado {8, -2, 9, 0, 13} con k=3
        { {8, -2, 9, 0, 13}, 5, 3, 9 },

        // Caso 10: arreglo de ejemplo dado {8, -2, 9, 0, 13} con k=4
        { {8, -2, 9, 0, 13}, 5, 4, 13 }
    };

    int result;

    printf("TESTING k_esimo\n");

    for (int i = 0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i + 1);

        result = k_esimo(tests[i].a, tests[i].length, tests[i].k);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }
    }

    return 0;
}
