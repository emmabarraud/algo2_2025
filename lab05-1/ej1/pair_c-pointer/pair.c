#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */
#include <assert.h>

pair_t pair_new(int x, int y) {
    pair_t p;
    p = malloc(sizeof(pair_t));
    p-> fst = x;
    p-> snd = y;
    return p;
}

int pair_first(pair_t p) {
return p->fst; 
}

int pair_second(pair_t p) {
return p->snd; 
}

pair_t pair_swapped(pair_t p){
    pair_t q;
    q = malloc(sizeof(pair_t));

    q->fst = p->snd;
    q->snd = p-> fst;
    assert(pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p));
    free(p);
    return q;
}

pair_t pair_destroy(pair_t p) {
    p-> fst = 0;
    p-> snd = 0;

    return p;
}


