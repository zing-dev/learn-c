#include<stdio.h>
struct size{
	char c;
	int i;
	long l;
};

int main(void)
{

	struct size s;
	// sizeof 16
	printf("size is %d\n",sizeof(struct size));
	printf("s is %d\n",sizeof(s));

	printf("s.long is %d\n",sizeof(s.l));
	return 0;
}

