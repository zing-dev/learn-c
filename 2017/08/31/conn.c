#include <stdio.h>
#include<mysql/mysql.h>

int main()
{
	MYSQL mysql;

	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql,"localhost","root","root","fgap_config",0,NULL,0)){
		printf("conn error.....\n");
	}else{
		printf("success......\n");
	}

}
