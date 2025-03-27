#include <stdio.h>
#include <stdlib.h>
#include "fixstring.h"

#define N_WORDS 2

void test_fstring_length(fixstring words[], int size) {
    printf("\nPrueba de fstring_length()\n");
    printf("-------------------------\n\n");
    
    for (int i = 0; i < size; i++) {
        printf("Longitud de '%s': %u caracteres\n", words[i], fstring_length(words[i]));
    }
}

void test_fstring_comparisons(fixstring words[], int size) {
    printf("\nPrueba de fstring_eq() y fstring_less_eq()\n");
    printf("-----------------------------------------\n\n");
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (fstring_eq(words[i], words[j])) {
                printf("Los strings '%s' y '%s' son IGUALES.\n", words[i], words[j]);
            } else {
                printf("Los strings '%s' y '%s' son DIFERENTES.\n", words[i], words[j]);
            }
            
            if (!fstring_less_eq(words[i], words[j])) {
                printf("'%s' va DESPUÉS de '%s' en orden alfabético.\n\n", words[i], words[j]);
            } else {
                printf("'%s' va ANTES o ES IGUAL a '%s' en orden alfabético.\n\n", words[i], words[j]);
            }
        }
    }
}

int main(void) {
    fixstring words[N_WORDS] = {"casa", "auto"};
    
    test_fstring_length(words, N_WORDS);
    test_fstring_comparisons(words, N_WORDS);
    
    return EXIT_SUCCESS;
}
