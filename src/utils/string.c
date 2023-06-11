#include "string.h"
#include <string.h>

HeapString
string_init(char *s)
{
    HeapString res = {0};
    res.data       = strdup(s);
    res.length     = strlen(s);
    return res;
}

void
string_deinit(HeapString *s)
{
    if (s)
    {
        free(s->data);
        s->length = 0;
    }
}

bool
string_match(HeapString *a, HeapString *b)
{
    assert(a && b);
    if (a->length != b->length) return false;
    if (a == b) return true;
    bool res = strcmp(a->data, b->data) == 0;
    return res;
}

void
string_append(HeapString *s, char *to_append)
{
    size_t input_len = strlen(to_append);
    size_t old_len   = s->length;
    size_t new_len   = old_len + input_len;
    s->data          = realloc(s->data, new_len + 1);

    memcpy(s->data + old_len, to_append, input_len);
    s->data[new_len] = 0;
}

HeapString
string_duplicate(HeapString *s)
{
    size_t len     = s->length;
    HeapString res = {0};
    res.data       = malloc(len + 1);
    strncpy(res.data, s->data, len);
    res.data[len] = 0;
    res.length    = len;
    return res;
}
