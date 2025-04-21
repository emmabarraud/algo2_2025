#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();
    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
        {{8}, 1, true},                        // único elemento (asumido cima)
        {{1, 3, 2}, 3, true},                  // pico en el medio
        {{1, 2, 3, 2}, 4, true},               // pico al final
        {{3, 2, 1}, 3, false},                 // sin pico, estrictamente decreciente
        {{1, 2, 3}, 3, false},                 // sin pico, estrictamente creciente
        {{1, 3, 3, 2}, 4, false},              // meseta, no es cima
        {{2, 1, 2}, 3, false},                 // valle, no es cima
        {{2, 4, 2, 4, 2}, 5, false},            // múltiples cimas
        {{5, 5, 5, 5}, 4, false},              // todos iguales, sin cima
        {{2, 5, 2, 6, 3}, 5, false}             // múltiples picos
    };

    bool result;

    printf("TESTING tiene_cima\n");

    for (int i = 0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i + 1);
        result = tiene_cima(tests[i].a, tests[i].length);
        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result; // índice de una cima
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        {{8}, 1, 0},                           // único elemento
        {{1, 3, 2}, 3, 1},                     // cima en el medio
        {{1, 2, 3, 2}, 4, 2},                  // cima al final
        {{3, 2, 1}, 3, -1},                    // sin cima
        {{1, 2, 3}, 3, -1},                    // sin cima
        {{1, 3, 3, 2}, 4, -1},                 // meseta, sin cima
        {{2, 4, 2, 4, 2}, 5, -1},               // primera cima
        {{5, 5, 5, 5}, 4, -1},                 // sin cima
        {{2, 5, 2, 6, 3}, 5, -1},               // primera cima
        {{2, 3, 4, 3, 2, 1}, 6, 2}             // cima en el medio
    };

    int result;

    printf("TESTING cima\n");

    for (int i = 0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i + 1);
        result = cima(tests[i].a, tests[i].length);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
