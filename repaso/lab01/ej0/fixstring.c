#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

//unsigned int fstring_length(fixstring s);
unsigned int fstring_length(fixstring s) {
    unsigned int i = 0;
    while (i < FIXSTRING_MAX && s[i] != '\0') {
        i++;
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool iguales = true;

    if (fstring_length(s1) != fstring_length(s2)) {
        iguales = false;
    }

    int i = 0;
    while (i < FIXSTRING_MAX) {
        if (s1[i] != s2[i]) {
            iguales = false;
        } 
    i++;
    }
return iguales;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;

    // ciclo: buscar la primer posición en la que los strings NO coinciden.
    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }

    // salimos del ciclo: s1[i] != s2[i] || s1[i] == '\0'

    // posibilidad 1: s1[i] < s2[i] → s1 va antes lexicográficamente
    if (s1[i] < s2[i]) {
        return true;
    }

    // posibilidad 2: s1[i] == s2[i] → ambos strings son iguales (los dos terminaron)
    if (s1[i] == s2[i]) {
        return true;
    }

    // posibilidad 3: s1[i] > s2[i] → s1 va después lexicográficamente
    return false;
}
