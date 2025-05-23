#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t length = 0;
    while(str[length] != '\0') {
        length++;
    }
    return length;
}

char *string_filter(const char *str, char c) {
    size_t length = string_length(str);
    size_t new_len = 0;

    //devuelve la longitud de la cadena sin el caracter c: 
    for (size_t i = 0; i < length; i++) {
        if (str[i] != c) {
            new_len++;
        }
    }

    char *filtered = malloc(sizeof(char) * (new_len + 1)); //libero memoria para el nuevo filtered
    if (filtered == NULL) return NULL;

    size_t j = 0;
    //para cada elemento en filtered lo apunto a lo que apunta str
    for (size_t i = 0; i < length; i++) {
        if (str[i] != c) {
            filtered[j++] = str[i];
        }
    }

    filtered[j] = '\0'; //al terminarañado el '\0'
    return filtered;
}


bool string_is_symmetric(const char *str) {
    size_t len = string_length(str);
    bool res = true;
    for (size_t i = 0; i < len / 2; i++) { //mira hasta la mitad 
        if (str[i] != str[len - i - 1]) {  // ->de atras para adelante
            res = false;       // quiebra si encuentra esa condicion
        }
    }
    return res;
}