#include "inc/def.h"
#include "inc/other.h"
#include "inc/vec.h"
#include "utils/string.h"

i32
main(void)
{
    HeapString s = string_init("bruh");
    string_append(&s, "bruh");
    HeapString s2 = string_duplicate(&s);

    printf("%s\n", s.data);
    printf("%s\n", s2.data);

    string_deinit(&s);
    string_deinit(&s2);
    return (0);
}
