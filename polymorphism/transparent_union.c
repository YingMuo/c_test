#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef enum GenericType GenericType;
typedef struct A A;
typedef struct B B;
typedef union GenericPtr GenericPtr;

enum GenericType {
    TYPE_A = 0,
    TYPE_B,
};

struct A {
    GenericType type;
    int x;
    int y;
};

struct B {
    GenericType type;
    float x;
    float y;
};

union GenericPtr {
    GenericType *type;
    A *A;
    B *B;
} __attribute__((__transparent_union__));

void foo (GenericPtr ptr) {
    switch (*ptr.type) {
    case TYPE_A:
        printf("%d\n", ptr.A->x + ptr.A->y);
        break;
    case TYPE_B:
        printf("%f\n", ptr.B->x + ptr.B->y);
        break;
    default:
        assert(false);
    }
}

int main(void)
{
    A a = { .type = TYPE_A, .x = 1, .y = 2 };
    B b = { .type = TYPE_B, .x = 1.1, .y = 2.2 };
    foo(&a);
    foo(&b);

    return 0;
}
