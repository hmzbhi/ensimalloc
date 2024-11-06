/******************************************************
 * Copyright Grégory Mounié 2018                      *
 * This code is distributed under the GLPv3+ licence. *
 * Ce code est distribué sous la licence GPLv3+.      *
 ******************************************************/

#include <stdint.h>
#include <assert.h>
#include "mem.h"
#include "mem_internals.h"

unsigned int puiss2(unsigned long size) {
    unsigned int p=0;
    size = size -1; // allocation start in 0
    while(size) {  // get the largest bit
	p++;
	size >>= 1;
    }
    if (size > (1 << p))
	p++;
    return p;
}


void *
emalloc_medium(unsigned long size) {
    assert(size < LARGEALLOC);
    assert(size > SMALLALLOC);
    
    /* unsigned int p = puiss2(size+32);
    void* temp;
    unsigned long size_blocs;

    
    if (arena.TZL[p] != NULL){
        temp = arena.TZL[p];
        arena.TZL[p] = *(void**) arena.TZL[p];

        return mark_memarea_and_get_user_ptr(arena.TZL[p],(1<<p),MEDIUM_KIND);
    } else {
        unsigned int i = 1;
        while  (arena.TZL[p+i] == NULL && p+i < (FIRST_ALLOC_MEDIUM_EXPOSANT + arena.medium_next_exponant)){
            i++;
        }
        if (p+i == (FIRST_ALLOC_MEDIUM_EXPOSANT + arena.medium_next_exponant)){
            size_blocs = mem_realloc_medium();
        } else {
            unsigned int current_len = p+i;
            while (current_len != p){
                -- A compléter pour finir emalloc_medium 
                current_len+= -1;
            }
        }
        return mark_memarea_and_get_user_ptr(temp,(1<<p),MEDIUM_KIND);
    } */
    return (void*) 0;
}


void efree_medium(Alloc a) {
    /* A compléter */
}


