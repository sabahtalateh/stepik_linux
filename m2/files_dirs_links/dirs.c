#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    int fd = open("/", O_RDONLY);
    DIR *dir = fdopendir(fd);

    struct dirent *entry;

    entry = readdir(dir);
    while (entry) {
        printf("%s ... %d ... %d\n", entry->d_name, (int) entry->d_ino, entry->d_type);
        entry = readdir(dir);
    }

    closedir(dir);
}
