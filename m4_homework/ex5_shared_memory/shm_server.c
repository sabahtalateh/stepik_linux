#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>

#define SHM_SIZE 27

int main() {
    char c;
    int shm_id;
    key_t key;
    char *shm, *s;

    key = 5678;

    /**
     * Create memory segment.
     */
    if ((shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /**
     * Attach segment to our data space.
     */
    if ((shm = shmat(shm_id, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /**
     * Put some thing to memory for the other process to read.
     */
    s = shm;
    for (c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    /**
     * Finally wait for other process
     * change first symbol in memory to '*'
     * that indicates that it has read what we put.
     */
    while (*shm != '*') {
        sleep(1);
    }

    exit(0);
}
