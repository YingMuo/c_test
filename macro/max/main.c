#include <stdio.h>

#define max(a, b)     \
({typeof(a) _a = a;   \
  typeof(b) _b = b;   \
  _a > _b ? _a : _b;})

int func_1(void)
{
    return 1;
}

int func_2(void)
{
    return 2;
}

int main(void)
{
    printf("%d\n", max(func_1(), func_2()));

    return 0;
}
