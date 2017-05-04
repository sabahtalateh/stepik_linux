#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>

#define SHM_SIZE 27

int main() {

    int shm_id;
    key_t key;
    char *shm, *s;

    /**
     * We will read '5678' segment that created by shm_server
     */
    key = 5678;

    /**
     * Locate the segment.
     */
    if ((shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /**
     * Attach the segment to our data space.
     */
    if ((shm = shmat(shm_id, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /**
     * Read from memory.
     */
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    /**
     * Mark memory as read.
     */
    *shm = '*';

    exit(0);
}
