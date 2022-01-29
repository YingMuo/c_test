#include <stdio.h>

#define offsetof(TYPE, MEMBER)   ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member)                            \
    __extension__({                                                \
        const __typeof__(((type *) 0)->member) *__pmember = (ptr); \
        (type *) ((char *) __pmember - offsetof(type, member));    \
    })

typedef struct _t
{
	int x;
	int y;
	int z;
} T;

int main(void)
{
	T t = {
		.x = 1,
		.y = 2,
		.z = 3,
	};

	int *y_ptr = &t.y;

	T *t_ptr = container_of(y_ptr, T, y);
	printf("%d\n", t_ptr->z);

	return 0;
}
