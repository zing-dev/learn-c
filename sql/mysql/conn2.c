#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<mysql/mysql.h>


int main(int argc,char *argv[])
{
	MYSQL mysql;

	char *host;
	char *user;
	char *password;

	int oc;
	char *b_opt_arg;

	printf("input host,user and password:\n");
	while((oc = getopt(argc, argv, "h:u:p:")) != -1){
		switch(oc) {
			case 'h':
				host = optarg;
				printf("h -> %s\n",host);
				break;
			case 'u':
				user = optarg;
				printf("u -> %s\n",user);
				break;
			case 'p':
				password = optarg;
				printf("pwd -> %s\n",password);
				break;
			default:
				printf("fuck\n");
		}
	}

	printf("argc --> %d\n",argc);
	if(argc != 7){
		printf("fuck!!!\n");
		exit(1);
	}

	if(mysql_init(&mysql) == NULL){
		printf("mysql_init() : %s\n",mysql_error(&mysql));
		return -1;
	}

	/***
	  * http://www.2cto.com/database/201506/407827.html
	  * MYSQL *mysql_real_connect(
	  *		MYSQL *mysql, 
	  *		const char *host, 
	  *		const char *user, 
	  *		const char *passwd, 
	  *		const char *db, 
	  *		unsigned int port,
	  *		const char *unix_socket, 
	  *		unsigned long client_flag
	  *	)
	  *
	  */
	if(mysql_real_connect(&mysql,host,user,password,"demo",0,NULL,0) == NULL){
		printf("mysql_real_connect() : %s\n",mysql_error(&mysql));
		return -1;
	}

	printf("connect success!!!\n");
	return 0;
}
