#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int
main(int argc, char *argv[])
{
// get ip solution taken from:
// https://stackoverflow.com/questions/1570511/c-code-to-get-the-ip-address?noredirect=1&lq=1
// and modified for our use.
// only works when enp0s31f6 ip is visable
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
                                           host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }
            if (0 == strcmp(ifa->ifa_name, "enp0s31f6")){
                printf((char *)host + strlen(host) - 2);
                break;
            }
        }
    }
    return 0;
}