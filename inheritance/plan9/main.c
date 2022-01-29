#include <stdio.h>

typedef struct S {
    int i;
} S;

typedef struct T {
    S;           // <- "inheritance"
    int j;
} T;

void bar(S *s) {
    s->i = 10;
}

void foo(T *t) {
    bar(t);   // <- call with implict conversion to "base class"
    // bar(&t->S); // <- explicit access to "base class"
}

int main(void)
{
    T t;
    foo(&t);
    printf("%d\n", t.S.i);
    return 0;
}
