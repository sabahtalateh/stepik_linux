#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

int main() {

    int fd = open("/tt", O_RDONLY);
    DIR *dir = fdopendir(fd);

    struct dirent *entry;

    entry = readdir(dir);

//    while (entry) {
//        entry = readdir(dir);

//        printf("%s - %d\n", entry->d_name, entry->d_type);
//    }

    return 0;
}
