#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

int ctr = 0;
jmp_buf jmpbuf;

void handler_fpe(int sig)
{
    printf("QQ\n");
    longjmp(jmpbuf, ctr);
}

int main(void)
{
    signal(SIGFPE, handler_fpe);

    switch (setjmp(jmpbuf))
    {
    case 0:
        ctr++;
        printf("%d\n", 1/1);
    case 1:
        ctr++;
        printf("%d\n", 1/0);
    case 2:
        ctr++;
        printf("%d\n", 1/2);
    default:
        break;
    }
    
    return 0;
}