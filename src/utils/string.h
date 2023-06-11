#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    size_t length;
    char *data;
} HeapString;

HeapString string_init(char *s);
void string_deinit(HeapString *s);
bool string_match(HeapString *a, HeapString *b);
void string_append(HeapString *s, char *to_append);
HeapString string_duplicate(HeapString *s);
