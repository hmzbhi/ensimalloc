/******************************************************
 * Copyright Grégory Mounié 2018                      *
 * This code is distributed under the GLPv3+ licence. *
 * Ce code est distribué sous la licence GPLv3+.      *
 ******************************************************/

#include <assert.h>
#include "mem.h"
#include "mem_internals.h"
unsigned long nbr_blocs;

void *
emalloc_small(unsigned long size)
{
    unsigned long size_bloc;

    if (nbr_blocs == 0){
        arena.chunkpool = NULL;
    }
    if (arena.chunkpool == NULL){
        size_bloc = mem_realloc_small();
        nbr_blocs = size_bloc/CHUNKSIZE; 
    }

    unsigned long i=0;
    while (i < nbr_blocs){
        void** temp = (void**) (((__uint8_t*) arena.chunkpool) + CHUNKSIZE*i);
        *temp = (void*) (((__uint8_t*) arena.chunkpool) + CHUNKSIZE*(i+1));
        i += 1;
    }

    void* adr_first_arena = arena.chunkpool;
    arena.chunkpool = (void*) (((__uint8_t*) arena.chunkpool) + CHUNKSIZE);
    nbr_blocs += -1;
    return mark_memarea_and_get_user_ptr(adr_first_arena,CHUNKSIZE,SMALL_KIND);
}

void efree_small(Alloc a) {
    void** temp = (void**) a.ptr;
    *temp = (void*) arena.chunkpool;
    arena.chunkpool = a.ptr;

}
