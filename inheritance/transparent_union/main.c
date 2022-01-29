#include <stdio.h>
#include <stdlib.h>

typedef struct _s S;
typedef struct _t T;
typedef union TPtr TPtr;

struct _s {
	int x;
	int y;
};

struct _t {
	S s;
	int z;
};

union TPtr {
    S *S;
    T *T;
} __attribute__((__transparent_union__));

void foo(TPtr t) {
    t.S->x = 10;
}


int main(void)
{
	S s;
	T t;
	foo(&s); // T * can be passed in as TPtr without explicit casting
	foo(&t);
	printf("%d\n", s.x);
	printf("%d\n", t.s.x);

	return 0;
}
