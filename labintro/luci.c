#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void responderPregunta() {
    char pregunta[100];
    int cantidadChabones;
    char respuesta[10];

    printf("\n\n\nEscribí tu pregunta: ");
    fgets(pregunta, sizeof(pregunta), stdin);

    // Verificamos si la pregunta es la que esperamos
    if (strstr(pregunta, "Es maia una puta?") != NULL) {
        printf("¿Con cuántos chabones habló esta semana? ");
        scanf("%d", &cantidadChabones);
        getchar(); // Consumimos el salto de línea que dejó scanf

        if (cantidadChabones >= 3) {
            printf("✅ Sí, putísima 😈🔥\n\n\n");
        } else {
            printf("😇 No, tranqui esta semana...\n");

            printf("🤔 Pero... ¿ya terminó la semana? (s/n): ");
            fgets(respuesta, sizeof(respuesta), stdin);

            if (respuesta[0] == 'n' || respuesta[0] == 'N') {
                printf("😏 Entonces no cantes victoria todavía...\n\n\n");
            } else {
                printf("✨ Bien ahí, se mantuvo digna esta vez 😌\n\n\n");
            }
        }
    } else {
        printf("No entiendo la pregunta...\n");
    }
}

int main() {
    responderPregunta();
    return 0;
}
