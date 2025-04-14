#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void responderPregunta() {
    char pregunta[100];

    printf("Escribí tu pregunta: ");
    fgets(pregunta, sizeof(pregunta), stdin);

    // Verificamos si la pregunta es la que esperamos (podés personalizar esta parte)
    if (strstr(pregunta, "Es la luci una puta?") != NULL) {
        // Semilla para números aleatorios
        srand(time(NULL));
        int respuesta = rand() % 2;

        if (respuesta == 0) {
            printf("Sí\n");
        } else {
            printf("No\n");
        }
    } else {
        printf("No entiendo la pregunta...\n");
    }
}

int main() {
    responderPregunta();
    return 0;
}