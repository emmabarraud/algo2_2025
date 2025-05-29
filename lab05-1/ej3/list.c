#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


struct _node {
    list_elem elem;
    struct _node *next;
};


//constructors
list empty(void) {
    return NULL;
}
/*- Crea una lista vacía. -*/


list addl(list_elem e, list l) {
    list a = malloc(sizeof(struct _node));
    assert(a != NULL);
    a->elem = e;
    a->next = l;
    l = a; // Update the head of the list to point to the new node
    return l;
} // Agrega e al inicio de la lista

// Destructor
void destroy(list l) {
    while (l!= NULL){ //recorrer y liberar toda la lista
        list tmp = l;
        l = l->next; // Avanza al siguiente nodo
        free(tmp); // Libera el nodo actual
    }
} 

// Operations
bool is_empty(list l) {
    return (l == NULL);
} // Retorna true si l es vacía

list_elem head(list l) {
    assert(!is_empty(l));
    return l->elem;
} // Retorna el primer elemento
// PRE: !is_empty(l)

list tail(list l){
    assert(!is_empty(l));
    //list a = malloc(sizeof(node)); no hace falta pedir memoria si se sobreescribe el puntero
    list a = l;
    l = l->next;
    free(a);
    return l;
} // Elimina el primer elemento y devuelve la nueva lista
// PRE: !is_empty(l)

list addr(list l, list_elem e) { 
    list b = malloc(sizeof(struct _node));
    assert(b != NULL);
    b->elem = e;
    b->next = NULL;

    if (!is_empty(l)) {
        list a = l;
        while (a->next != NULL) {
            a = a->next; 
        }
        a->next = b;
    } else {
        l = b;
    }
    return l;
}

    // Agrega e al final de l

unsigned int length(list l) {
    unsigned int n = 0;
    list a = l;
    while (a != NULL) {
        n++;
        a = a->next;
    }
    return n;
} // Devuelve la longitud de l

list concat(list l, list l0) {
    if (!is_empty(l)) {
        list a = l;
        while (a->next != NULL) {
            a = a->next; 
        }
        a->next = copy_list(l0);
    } else {
        l = copy_list(l0);
    }
    return l;
} // Agrega al final de l todos los elementos de l0

list_elem index(list l, unsigned int n){
    assert(length(l) > n);
    list a = l;
    for (unsigned int i = 0; i < n; i++) {
        a = a->next; // Avanza al siguiente nodo
    }
    return a->elem; //
} // Retorna el n-ésimo elemento
// PRE: length(l) > n

list take(list l, unsigned int n) {
    list a = l;
    for (unsigned int i = 0; i < n && a-> next !=NULL; i++) {
        a = a-> next;
    }
    if (a != NULL && a->next != NULL) {
        a->next = NULL; // Termina la lista en el nodo actual
    }
    return l;
} // Deja en l los primeros n elementos

list drop(list l, unsigned int n) {
    for (unsigned int i = 0; i < n && l !=NULL; i++) {
        list tmp = l; // Guarda el nodo actual
        l = l->next; // Avanza al siguiente nodo
        free(tmp); // Libera el nodo actual
    }
    return l; // Devuelve la lista sin los primeros n elementos    
} // Elimina los primeros n elementos

list copy_list(list l){
    list new_list = empty(); // Crea una nueva lista vacía
    list *current = &new_list; // Puntero para construir la nueva lista
    while (l != NULL) {
        *current = malloc(sizeof(struct _node)); //
        assert(*current != NULL); //
        (*current)->elem = l->elem; 
        (*current)->next = NULL; //
        current = &((*current)-> next); 
        l = l->next; 
    }
    return new_list;
} // Copia todos los elementos de l en una nueva lista
