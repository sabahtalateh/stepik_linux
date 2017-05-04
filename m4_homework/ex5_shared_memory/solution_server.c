#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SHMSZ 1000

int main() {

    int shmid1, shmid2;
    key_t key1, key2;
    int *shm1, *shm2;

    key1 = 1111;
    key2 = 2222;

    /**
     * Get.
     */
    if ((shmid1 = shmget(key1, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shmid2 = shmget(key2, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /**
     * Attach.
     */
    if ((shm1 = shmat(shmid1, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }
    if ((shm2 = shmat(shmid2, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    int i = 0;
    int *p1 = shm1;
    int *p2 = shm2;

    for (; i < SHMSZ / sizeof(int); ++i) {
        *p1++ = 4;
        *p2++ = 7;
    }

    printf("%d %d\n", key1, key2);

    while (true) {
        if (*shm1 == -1 && *shm2 == -1) {
            break;
        }
        sleep(1);
    }

    return 0;
}
