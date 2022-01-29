#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	link("aaa", "bbb");
	return 0;
}
