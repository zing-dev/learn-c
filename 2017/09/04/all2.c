#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <string.h>
#include <stdlib.h>
int get_all_macs(char **result);
int main(int argc, char *argv[])
{
	char **result = (char **) malloc(1024);
	get_all_macs(result);
	int i;
	for(i = 0; i < (sizeof(result) / sizeof(result[i]));i++){
		if(strlen(result[i]) < 14) {
			continue;
		}
		printf("eth%d\'s MAC is %s\n",i,result[i]);
	}

	return 0;

}
int get_all_macs(char **result)
{ 
	struct ifreq ifreq;
	int sock;
	int i;
	for(i = 0; i < 10; i++){
		char *eth = "";
		sock = socket(AF_INET, SOCK_STREAM, 0);
		//if(sock = socket(AF_INET, SOCK_STREAM, 0) < 0){}
		sprintf(eth,"eth%d",i);
		strcpy(ifreq.ifr_name,eth);
		if(ioctl(sock,SIOCGIFHWADDR,&ifreq) < 0){
			continue;
		}
		sprintf(*(result + i*sizeof(char)),"%02x:%02x:%02x:%02x:%02x:%02x",(unsigned char)ifreq.ifr_hwaddr.sa_data[0],(unsigned char)ifreq.ifr_hwaddr.sa_data[1],
		(unsigned char)ifreq.ifr_hwaddr.sa_data[2],(unsigned char)ifreq.ifr_hwaddr.sa_data[3],(unsigned char)ifreq.ifr_hwaddr.sa_data[4],(unsigned char)ifreq.ifr_hwaddr.sa_data[5]);
	}
	return 0;
}

