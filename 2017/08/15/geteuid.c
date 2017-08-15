#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
void main()
{
	printf("euid is %d \n",geteuid());
}
