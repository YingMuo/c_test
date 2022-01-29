#include <stdio.h>
#include <stdlib.h>

#define autofree \
    __attribute__((cleanup(free_stack)))

__attribute__ ((always_inline))
inline void free_stack(void *ptr) { free(*(void **) ptr); }

int main(void) {
    autofree int *i = malloc(sizeof (int));
    *i = 1;
    return *i;
}
