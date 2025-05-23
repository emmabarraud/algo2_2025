#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "data.h"


void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {


    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

// 1. tamaños de cada campo y de la estructura completa usando sizeof
    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(data_t));
    
// 2. direcciones de memoria 
// %p puntero a void (void*) ->direccion de memoria apuntada por (ej: messi.name)
// puntero a un entero sin signo: que es el tipo uintptr_t (%lu) -> indices de memoria
    printf("Direcciones de memoria:\n");
    printf("Dirección de name   : %p (índice: %lu)\n", (void*)&messi.name, (uintptr_t)&messi.name);
    printf("Dirección de age    : %p (índice: %lu)\n", (void*)&messi.age, (uintptr_t)&messi.age);
    printf("Dirección de height : %p (índice: %lu)\n\n", (void*)&messi.height, (uintptr_t)&messi.height);


    // 3. memoria dinámica (heap

    data_t *dynamic_data = malloc(sizeof(data_t)); //espacio liberado para algo de tamaño data_t
    if (dynamic_data == NULL) {
        fprintf(stderr, "Error al reservar memoria\n");
        return EXIT_FAILURE;
    }

    strcpy(dynamic_data->name, "Leo Messi");
    dynamic_data->age = 36;
    dynamic_data->height = 169;

    print_data(*dynamic_data);

    printf("Direcciones de dynamic_data:\n");
    printf("Dirección de name   : %p (índice: %lu)\n", (void*)&(dynamic_data->name), (uintptr_t)&(dynamic_data->name));
    printf("Dirección de age    : %p (índice: %lu)\n", (void*)&(dynamic_data->age), (uintptr_t)&(dynamic_data->age));
    printf("Dirección de height : %p (índice: %lu)\n", (void*)&(dynamic_data->height), (uintptr_t)&(dynamic_data->height));

    free(dynamic_data); // liberar memoria




    return EXIT_SUCCESS;
}


/*
visitante@lab24:~/Descargas/lab04/ej3/a-sizes$ ./sizes

NOMBRE: Leo Messi
EDAD  : 36 años
ALTURA: 169 cm

name-size  : 30 bytes
age-size   : 4 bytes
height-size: 4 bytes
data_t-size: 40 bytes

Osea -> la suma de los miembros no coincide con el total
El tamaño de name no depende del nombre---- Name es un array de tamaño fijo, siempre va a ocupar 30Bytes


Direcciones de memoria:
Dirección de name   : 0x7ffe05a28580 (índice: 140728992957824)
Dirección de age    : 0x7ffe05a285a0 (índice: 140728992957856)
Dirección de height : 0x7ffe05a285a4 (índice: 140728992957860)

- Alineamiento de datos en memoria

NOMBRE: Leo Messi
EDAD  : 36 años
ALTURA: 169 cm

Direcciones de dynamic_data:
Dirección de name   : 0x62e3c98626b0 (índice: 108730478110384)
Dirección de age    : 0x62e3c98626d0 (índice: 108730478110416)
Dirección de height : 0x62e3c98626d4 (índice: 108730478110420)
*/