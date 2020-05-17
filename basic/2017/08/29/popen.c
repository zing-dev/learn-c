#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    FILE *fp = NULL;
    char cmd[512];
//	sprintf(cmd, "ls 2>/dev/null; echo $?");
    sprintf(cmd, "ls /");
    printf("%s\n", cmd);
    if ((fp = popen(cmd, "r")) != NULL) {

//		while((fread(cmd,sizeof(cmd),sizeof(cmd),fp)) != '\0'){
//			puts(cmd);
//			printf("-->  %s\n",cmd);
//		}

        memset(cmd, 0, sizeof(cmd));
        fgets(cmd, sizeof(fp), fp);
        printf("%s\n", cmd);
        pclose(fp);
    }//0 成功， 1 失败
    printf("cmd is %s\n", cmd);
    return 0;
}
