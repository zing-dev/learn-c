#include <stdio.h>
//#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
	//将主机数转换成无符号长整型的网络字节顺序。
	//本函数将一个32位数从主机字节顺序转换成网络字节顺序。

	printf("%d\n",htonl(INADDR_ANY));
	printf("%d\n",htonl(10));
	printf("%d\n",htonl(10u));

	/**
	int mhtonl = 10; 
	int *p = &mhtonl;
	printf("%d\n",&mhtonl);
	printf("%d\n",p);
	printf("p --> %d\n",(uint32_t)htonl(&mhtonl));

	*/

	int a = 0x403214;
	int b = htonl(a);
	printf("a --> %d\n",a);
	printf("b --> %d\n",htonl(a));

}
