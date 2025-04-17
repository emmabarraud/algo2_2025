#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Estructura para representar un float en formato IEEE 754 (32 bits)
typedef union {
    float f;
    uint32_t i;
    struct {
        uint32_t mantissa : 23;
        uint32_t exponent : 8;
        uint32_t sign : 1;
    } parts;
} ieee754_float;

// Función para imprimir la representación binaria de 32 bits
void print_binary32(uint32_t value) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if ((i == 31) || (i == 23)) {
            printf(" "); // Separadores para signo y exponente
        }
    }
    printf("\n");
}

int main() {
    float numero;
    ieee754_float ieee_rep;

    printf("Ingrese un número de punto flotante: ");
    scanf("%f", &numero);

    ieee_rep.f = numero;

    printf("Representación IEEE 754 de %f:\n", numero);
    printf("Signo: %u\n", ieee_rep.parts.sign);
    printf("Exponente (decimal): %d (bias = 127)\n", ieee_rep.parts.exponent);
    printf("Mantisa (hexadecimal): 0x%X\n", ieee_rep.parts.mantissa);
    printf("Representación binaria (signo exponente mantisa):\n");
    print_binary32(ieee_rep.i);

    return 0;
}