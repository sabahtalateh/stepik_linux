#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>

int main() {
    char *proc_dir = "/proc";

    struct stat dir_stat;
    stat(proc_dir, &dir_stat);

    if (!S_ISDIR(dir_stat.st_mode)) {
        printf("There is no %s dir in your fs\n", proc_dir);
        return 0;
    }

    int fd = open(proc_dir, O_RDONLY);
    DIR *dir = fdopendir(fd);

    struct dirent *entry;

    entry = readdir(dir);

    int c = 0;

    while (entry) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0) {

            char proc_file_path[256];
            sprintf(proc_file_path, "/proc/%s/status", entry->d_name);

            FILE *proc = fopen(proc_file_path, "r");
            char buff[400];

            while (fgets(buff, 200, proc)) {
                if (strstr(buff, "Name:")) {
                    char key[500];
                    char value[500] = "";
                    sscanf(buff, "%[^:]  :%s", key, value);
                    if (strcmp(value, "genenv") == 0) {
                        ++c;
                    }
                }
            }
        }

        entry = readdir(dir);
    }

    closedir(dir);

    printf("%d\n", c);

    return 0;
}
