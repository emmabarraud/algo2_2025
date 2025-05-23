#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 40

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered=NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    //scanf("%s", user_input);
    fgets(user_input, MAX_LENGTH, stdin); //lee toda la linea
    user_input[strcspn(user_input, "\n")] = '\0';
        // Eliminar el salto de línea al final de la entrada


    filtered = string_filter(user_input, ignore_chars[0]);
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        // Liberamos la memoria anterior antes de sobreescribir 'filtered'
        char *temp = string_filter(filtered, ignore_chars[i]);
        free(filtered); // Liberamos la memoria de la cadena anterior
        filtered = temp; // Asignamos el nuevo valor
    }

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");

    free(filtered);        
    return EXIT_SUCCESS;
}

/*Un palíndromo (también, palindromo o palindroma; del griego πάλιν δρóμος, palin dromos, ‘volver a ir atrás’) es una palabra o frase que se lee igual en un sentido que en el otro[1]​ (por ejemplo; Ana, Anna, Otto). Si se trata de números en lugar de letras, se llama capicúa.[2
*/

//scanf lee solo una palabra sin espacios

//Valgrind es una herramienta de programación utilizada para la depuración de programas,