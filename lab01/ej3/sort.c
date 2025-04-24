#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int partition(int a[], unsigned int lft, unsigned int rgt) {
    unsigned int ppiv = lft;
    unsigned int i = lft + 1u;
    unsigned int j = rgt;

    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (!goes_before(a[j], a[ppiv])) {
            j = j - 1;
        } else if (!goes_before(a[i], a[ppiv]) && goes_before(a[j], a[ppiv])) {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (der > izq) {


        unsigned int ppiv = partition(a, izq, der);


        if (ppiv > 0) {
            quick_sort_rec(a, izq, ppiv - 1);
        }
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    if (length > 0) {
        quick_sort_rec(a, 0, length - 1);
    }
}
