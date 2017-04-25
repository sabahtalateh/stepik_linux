#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>

void find_children_for_pid(char const *pid, char *proc[100000][2], int *added_count, int *passed_count, int *proc_count,
                           char *proc_dir) {

//    printf("proc = %s, passed = %d\n", pid, *passed_count);

    int fd = open(proc_dir, O_RDONLY);

    DIR *dir = fdopendir(fd);

    struct dirent *entry;
    entry = readdir(dir);

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
                    if (strcmp(value, pid) == 0) {
                        proc[*added_count][0] = entry->d_name;
                        proc[*added_count][1] = "f";
                        *added_count += 1;

                        printf("%s\n", entry->d_name);
                        *proc_count += 1;
                    }
                }
            }
        }

        entry = readdir(dir);
    }

    closedir(dir);

    *passed_count += 1;
}

int main(int argc, char **argv) {


    char *proc_dir = "/proc";

    struct stat dir_stat;
    stat(proc_dir, &dir_stat);

    if (!S_ISDIR(dir_stat.st_mode)) {
        printf("There is no %s dir in your fs\n", proc_dir);
    }

    char *first_pid = argv[1];

    char *proc[100000][2];
    proc[0][0] = first_pid;
    proc[0][1] = "f";

    int proc_count = 1;
    int passed_count = 0;
    int added_count = 1;

    while (passed_count != added_count) {
        find_children_for_pid(proc[passed_count][0], proc, &added_count, &passed_count, &proc_count, proc_dir);
    }


    printf("\n%d\n", proc_count);
    printf("passed - %d\n", passed_count);
    printf("added - %d\n", added_count);


    printf("total children - %d\n", added_count);
    printf("%d\n", proc_count);

    return 0;
}

