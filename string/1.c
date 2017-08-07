#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = "abc";
	char *str2 = "abc";
	if( strcmp(str,str2) == 0 )
	{
		printf("success\n");
	}else{
		printf("fail\n");
	}
}
