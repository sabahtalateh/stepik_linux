#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SHMSZ 1000

int main(int argc, char *argv[]) {

    int shmid_sum;
    key_t key;

    key = 8765990;

    if ((shmid_sum = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    int *shm_sum;
    if ((shm_sum = shmat(shmid_sum, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    int shmid1, shmid2;
    key_t key1, key2;
    int *shm1, *shm2;

    key1 = atoi(argv[1]);
    key2 = atoi(argv[2]);

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
     * Attach the segment to our data space.
     */
    if ((shm1 = shmat(shmid1, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }
    if ((shm2 = shmat(shmid2, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    int sum1 = 0, sum2 = 0;
    int i = 0;
    for (; i <= 100; ++i) {
        *(shm_sum + i) = *(shm1 + i) + *(shm2 + i);
    }

//    i = 0;
//    for (; i < 100; ++i) {
//        printf("%d\n", *(shm_sum + i));
//    }

    printf("%d\n", key);

    return 0;
}
