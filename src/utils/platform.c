#include "../inc/platform.h"

void *
mem_alloc(usize size)
{
    void *result = malloc(size);
    return (result);
}

void *
mem_realloc(void *mem_block, usize size)
{
    void *result = realloc(mem_block, size);
    return (result);
}

void
mem_free(void *mem_block)
{
    void *ptr = mem_block;
    free(ptr);
}
