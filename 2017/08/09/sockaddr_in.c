//
// Created by 张荣响 on 2017/8/9.
//

#include <stdio.h>
#include <arpa/inet.h>

/*
 * Socket address, internet style.
 */
struct sockaddr_in {
    __uint8_t	sin_len; //1
    sa_family_t	sin_family; //1
    in_port_t	sin_port;//2
    struct	in_addr sin_addr;//4
    char		sin_zero[8]; //8
};

/*
 * Internet address (a structure for historical reasons)
 */
struct in_addr {
    in_addr_t s_addr;
};


int main()
{

    struct sockaddr_in client_name;
    int client_name_len = sizeof(client_name);
    printf("%d\n",client_name_len);

}