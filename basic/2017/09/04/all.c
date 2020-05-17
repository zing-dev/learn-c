#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <string.h>

int get_all_macs(char result[5][20]);

int main(int argc, char *argv[]) {
    char result[10][20];
    get_all_macs(result);
    int i;
    for (i = 0; i < (sizeof(result) / sizeof(result[i])); i++) {
        if (strlen(result[i]) < 14) {
            continue;
        }
        printf("eth%d\'s MAC is %s\n", i, result[i]);
    }

    return 0;

}

int get_all_macs(char result[5][20]) {
    struct ifreq ifreq;
    int sock;

    /**
    if(argc!=2) {
        printf("Usage : ethname\n");
        return 1;
    }
    */

    /**
    if((sock=socket(AF_INET,SOCK_STREAM,0))<0){
        perror("socket.......");
        return 2;
    }
    */
    int i;
    for (i = 0; i < 10; i++) {
        char eth[5];
        sock = socket(AF_INET, SOCK_STREAM, 0);
        //if(sock = socket(AF_INET, SOCK_STREAM, 0) < 0){}
        sprintf(eth, "eth%d", i);
        strcpy(ifreq.ifr_name, eth);
        if (ioctl(sock, SIOCGIFHWADDR, &ifreq) < 0) {
//			perror("ioctl error..............................................................");
            continue;
        }
        sprintf(result[i], "%02x:%02x:%02x:%02x:%02x:%02x", (unsigned char) ifreq.ifr_hwaddr.sa_data[0],
                (unsigned char) ifreq.ifr_hwaddr.sa_data[1],
                (unsigned char) ifreq.ifr_hwaddr.sa_data[2], (unsigned char) ifreq.ifr_hwaddr.sa_data[3],
                (unsigned char) ifreq.ifr_hwaddr.sa_data[4], (unsigned char) ifreq.ifr_hwaddr.sa_data[5]);

    }

    return 0;
    /**
    strcpy(ifreq.ifr_name,argv[1]);
    if(ioctl(sock,SIOCGIFHWADDR,&ifreq)<0){
        perror("ioctl.......");
        return 3;
    }
    printf("%02x:%02x:%02x:%02x:%02x:%02x\n",(unsigned char)ifreq.ifr_hwaddr.sa_data[0],(unsigned char)ifreq.ifr_hwaddr.sa_data[1],
        (unsigned char)ifreq.ifr_hwaddr.sa_data[2],(unsigned char)ifreq.ifr_hwaddr.sa_data[3],(unsigned char)ifreq.ifr_hwaddr.sa_data[4],(unsigned char)ifreq.ifr_hwaddr.sa_data[5]);
    return 0;
    */
}

