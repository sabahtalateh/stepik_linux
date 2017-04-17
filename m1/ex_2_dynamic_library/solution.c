#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int (*func)(int);

bool load_lib(const char *lib_path, const char *fun_name) {
    void *hdl = dlopen(lib_path, RTLD_LAZY);

    if (NULL == hdl) {
        return false;
    }

    func = dlsym(hdl, fun_name);

    if (NULL == func) {
        return false;
    }

    return true;
};

int main(int argc, char **argv) {

    char *lib_path = argv[1];
    char *fun_name = argv[2];
    int arg = atoi(argv[3]);

    if (load_lib(lib_path, fun_name)) {
        printf("%d\n", func(arg));
    }

    return 0;
}