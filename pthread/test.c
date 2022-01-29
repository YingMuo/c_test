#include <stdio.h>
#include <pthread.h>

void *func(void *data)
{
    for(int i = 0; i < 1000000000; ++i)
        printf("bababa\n");
}

int main(void)
{
    pthread_t t[4];
    for (int i = 0; i < 4; ++i)
    {
        pthread_create(&t[i], NULL, func, NULL);
    }
    for (int i = 0; i < 4; ++i)
    {
        pthread_join(t[i], NULL);
    }

    return 0;
}