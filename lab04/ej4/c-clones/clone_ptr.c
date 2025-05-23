#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ansicolors.h"

#define MAX_LENGTH 1820
/*
char *string_clone(const char *str, size_t length) {
    char clon[MAX_LENGTH];
    char *output=clon;
    for (size_t i=0; i<length;i++) {
        output[i] = str[i];
    }
    output[length] = '\0';
    return output;
}*/
//el problema es que 
//retorna un puntero a una variable local (clon), cuya memoria deja de ser válida al salir de la función, lo que causa comportamiento indefinido.

/*retornando un puntero (output) que apunta a ese array local. Por eso, cuando luego accedes a copy en main, estás accediendo a memoria que ya no deberías estar usando, lo que puede resultar en:

Datos incorrectos o basura.

Fallos en tiempo de ejecución (crash).

Comportamiento errático e impredecible.
*/

/*¿Cómo solucionarlo?
Necesitás usar memoria dinámica (heap), es decir, reservar memoria con malloc:
*/

char *string_clone(const char *str, size_t length) {
    char *output = malloc(length + 1);  // +1 para el '\0'
    if (output == NULL) {
        fprintf(stderr, "No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < length; i++) {
        output[i] = str[i];
    }
    output[length] = '\0';
    return output;
}

int main(void) {
    char *original=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         ANSI_BRGOLD
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                           Episode II \n\n"
         "                      ATTACK OF THE CLONES\n\n"
         "                There is  unrest in the Galactic\n"
         "                Senate. Several  thousand  solar\n"
         "                systems  have   declared   their\n"
         "                intentions to leave the Republic.\n\n"
         "                This      separatist     movement,\n"
         "                under  the   leadership   of  the\n"
         "                mysterious   Count   Dooku,   has\n"
         "                made it difficult for the limited\n"
         "                number   of   Jedi   Knights   to\n"
         "                maintain   peace   and  order  in\n"
         "                the galaxy.\n\n"
         "                Senator   Amidala,   the   former\n"
         "                Queen   of  Naboo,  is  returning\n"
         "                to  the  Galactic  Senate to vote\n"
         "                on the critical issue of creating\n"
         "                an    ARMY    OF   THE   REPUBLIC\n"
         "                to    assist    the   overwhelmed\n"
         "                Jedi....\n" ANSI_WHITE;
    char *copy=NULL;

    copy = string_clone(original, sizeof(original)/sizeof(*original));
    printf("Original:\n" ANSI_CYAN
            " %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   :\n" ANSI_CYAN
           " %s\n", copy);

    return EXIT_SUCCESS;
}

//el valor de length es exactamente la longitud total del string original, incluyendo el '\0', lo cual es correcto en este contexto.

//sizeof(arr) / sizeof(*arr) solo sirve si arr es un array real, no un puntero.

/*char *original = "...";
declara original como un puntero a char, no un array de char.

Por eso, cuando hacés:

sizeof(original) / sizeof(*original)
equivale a:

sizeof(char *) / sizeof(char)
Que en una arquitectura de 64 bits normalmente da:

8 / 1 = 8
⚠️ ¡Eso no representa la cantidad de caracteres en el string! Por eso el compilador te lanza esta advertencia (y error, porque activaste -Werror): estás dividiendo tamaños de tipos, no contando elementos de un array.

*/