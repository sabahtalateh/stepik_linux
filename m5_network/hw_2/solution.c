#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

struct sockaddr_in local;

int main(int c, char *v[]) {
    if (c != 2) {
        return -1;
    }

    int s = socket(AF_INET, SOCK_DGRAM, 0);

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(atoi(v[1]));
    local.sin_family = AF_INET;

    int result = bind(s, (struct sockaddr *) &local, sizeof(local));

    char buf[BUFSIZ];
    while (true) {
        read(s, buf, BUFSIZ);
        if ((strcmp(buf, "OFF") == 0) || (strcmp(buf, "OFF\n") == 0)) {
            close(s);
            break;
        }
        printf("%s\n", buf);
        memset(buf, 0, sizeof(buf));
    }

}
