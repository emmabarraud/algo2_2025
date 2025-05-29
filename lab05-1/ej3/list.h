#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdbool.h>

typedef int list_elem;
typedef struct _node *list; // encapsulando

// Constructors
list empty(void); // Crea una lista vacía
list addl(list_elem e, list l); // Agrega e al inicio de la lista

// Destructor
void destroy(list l); // Libera toda la memoria usada por l

// Operations
bool is_empty(list l); // Retorna true si l es vacía

list_elem head(list l); // Retorna el primer elemento
// PRE: !is_empty(l)

list tail(list l); // Elimina el primer elemento y devuelve la nueva lista
// PRE: !is_empty(l)

list addr(list l, list_elem e); // Agrega e al final de l

unsigned int length(list l); // Devuelve la longitud de l

list concat(list l, list l0); // Agrega al final de l todos los elementos de l0

list_elem index(list l, unsigned int n); // Retorna el n-ésimo elemento
// PRE: length(l) > n

list take(list l, unsigned int n); // Deja en l los primeros n elementos

list drop(list l, unsigned int n); // Elimina los primeros n elementos

list copy_list(list l); // Copia todos los elementos de l en una nueva lista

#endif