#pragma once

/*
    Platform layer
*/

#include "def.h"

/* Log */
// TODO: Add logging functions here

/*
    Memory Allocation:
        override when needed for different platform
*/
void *mem_alloc(usize size);
void *mem_realloc(void *mem_block, usize size);
void mem_free(void *mem_block);
