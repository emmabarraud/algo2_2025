#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 10

int main() {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 },                    // Caso 1: Solo un elemento, el pico es 8 (índice 0)
        { {1, 3, 2}, 3, 1 },              // Caso 2: Pico en el medio (índice 1)
        { {1, 2, 3, 4, 5}, 5, 4 },        // Caso 3: Pico al final (índice 4)
        { {5, 4, 3, 2, 1}, 5, 0 },        // Caso 4: Pico al principio (índice 0)
        { {1, 2, 3, 2, 1}, 5, 2 },        // Caso 5: Pico en el medio (índice 2)
        { {3, 5, 4}, 3, 1 },              // Caso 6: Pico en el medio (índice 1)
        { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 9 }, // Caso 7: Pico al final (índice 9)
        { {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 10, 0 }, // Caso 8: Pico al principio (índice 0)
        { {1, 3, 5, 7, 6, 4, 2}, 7, 3 },  // Caso 9: Pico en el medio (índice 3)
        //{ {1, 2, 1, 2, 1, 2}, 6, -2 },     // Caso 10: Pico alterno, el primer pico está en el índice 1
    };

    int result;

    printf("TESTING cima\n");

    for (int i = 0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i + 1);

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
