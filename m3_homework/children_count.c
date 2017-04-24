#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, int element) {
    // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
    // Therefore a->used can go up to a->size
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

int main(int argc, char **argv) {
    char *proc_dir = "/proc";

    struct stat dir_stat;
    stat(proc_dir, &dir_stat);

    if (!S_ISDIR(dir_stat.st_mode)) {
        printf("There is no %s dir in your fs\n", proc_dir);
        return 1;
    }

    int fd = open(proc_dir, O_RDONLY);
    DIR *dir = fdopendir(fd);

    struct dirent *entry;
    entry = readdir(dir);

    char *pids[0] = {};

    int c = 0;

    Array a;
    int i;
    initArray(&a, 5);
    for (i = 0; i < 300; i++) {
        insertArray(&a, i);
    }
    printf("%d\n", a.array[9]);  // print 10th element
    printf("%d\n", (int) a.size);  // print 10th element
    printf("%d\n\n\n", (int) a.used);

    while (entry) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0) {

            char proc_file_path[256];
            sprintf(proc_file_path, "/proc/%s/status", entry->d_name);

            FILE *proc_status = fopen(proc_file_path, "r");
            char buff[400];

            while (fgets(buff, 400, proc_status)) {
                if (strstr(buff, "PPid:")) {
                    char key[200];
                    char value[200];
                    sscanf(buff, "%[^:] :%s", key, value);
                    if (strcmp(value, "1") == 0) {
//                        pids[sizeof(pids) + sizeof(char)] = {};
                        ++c;
                    }
                }
            }
        }

        entry = readdir(dir);
    }

    printf("%d\n", c);

    closedir(dir);

//    char *pids[1] = {"1"};

//    char *new_pids[sizeof(pids) + sizeof(char)] = {"1", "2"};


    return 0;
}

