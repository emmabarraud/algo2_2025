#include <stdio.h>
#include <stdlib.h>

#include "fixstring.h"

#define N_WORDS 4

int main(void) {
    fixstring words[N_WORDS] = {"hola", "mundo", "a", ""};

    for (int i = 0; i < N_WORDS; i++) {
        printf("La longitud de '%s' es %u\n", words[i], fstring_length(words[i]));
    }

    for (int i = 0; i < N_WORDS; i++) {
        for (int j = 0; j < N_WORDS; j++) {
            if (fstring_eq(words[i], words[j])) {
                printf("'%s' y '%s' son iguales\n", words[i], words[j]);
            }
            printf("'%s' va %s alfabeticamente que '%s'\n\n", 
                   words[i], 
                   fstring_less_eq(words[i], words[j]) ? "antes" : "despues", 
                   words[j]);
        }
    }
    return EXIT_SUCCESS;
}
