#include<stdio.h>

int main(void)
{
	int port = 10086;
	int *p = &port;
	printf("%d\n", htons(10086));
	printf("%d\n", htons(*p));
}
