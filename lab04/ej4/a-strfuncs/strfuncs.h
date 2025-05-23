#ifndef _STRFUNCS_H_
#define _STRFUNCS_H_

#include <stdbool.h>

/**
 * @brief calcula la longitud de la cadena apuntada por str
 */
size_t string_length(const char *str);

/**
 * @brief devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str que son distintos del caracter c
 */
char *string_filter(const char *str, char c);

/**
 * @brief devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str que son distintos del caracter c
 */
bool string_is_symmetric(const char *str);


#endif