#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdbool.h>

struct sockaddr_in local;

int compare(const void *a, const void *b)
{
    return *(const char *)b - *(const char *)a;
}

int main(int c, char *v[]) {
    int conn_socket = socket(AF_INET, SOCK_STREAM, 0);
    int socket;

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(atoi(v[1]));
    local.sin_family = AF_INET;

    bind(conn_socket, (struct sockaddr *) &local, sizeof(local));
    listen(conn_socket, 5);

    socket = accept(conn_socket, NULL, NULL);

    char buf[BUFSIZ];
    while (true) {
        memset(buf, 0, BUFSIZ);
        read(socket, buf, BUFSIZ);

        if ((strncmp("OFF", buf, 3) == 0)) {
            close(socket);
            break;
        }

        if (strlen(buf) != 0) {
            qsort(buf, strlen(buf), 1, compare);
            sprintf(buf, "%s\n", buf);
            write(socket, buf, strlen(buf));
        }
    }


    return 0;
}
