#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>


int main(int c, char *v[]) {

    if (c < 2)
        return -1;

    struct hostent *h;
    h = gethostbyname(v[1]);

    int i = 0;

    while (true) {
        if (h->h_addr_list[i] == NULL) break;
        struct in_addr *a = (struct in_addr *) h->h_addr_list[i];
        printf("%s\n", inet_ntoa(*a));
        i++;
    }

    return 0;
}
