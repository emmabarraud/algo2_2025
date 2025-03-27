#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i = 0;
    while (i < FIXSTRING_MAX && s[i] != '\0') ++i ;
    return i; //contador 
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    bool valor = true;
    while (i < FIXSTRING_MAX && s1[i] != '\0' && s2[i] != '\0') {
        if ( s1[i] != s2[i]) valor = false;
        ++i;
    }
        if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0') ) valor = false; 
    return valor;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    bool valor = true;  
    while (i < FIXSTRING_MAX && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] <= s2[i]) {
            valor = true;  
        } else if (s1[i] > s2[i]) {
            valor = false;  
        }
        ++i;
    }

    if (s1[i] == '\0' && s2[i] != '\0') {
        valor = true;  
    } else if (s1[i] != '\0' && s2[i] == '\0') {
        valor = false;  
    }

    return valor;
}