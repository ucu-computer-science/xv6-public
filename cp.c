#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

int is_directory(struct stat *st) {
    return st->type == T_DIR;
}

void cp(char *from, char *to) {
    int fd1, fd2, n;
    char buf[512];

    struct stat st_1;

    if (stat(from, &st_1) < 0){
        printf(1, "Error in source file\n");
    }

    if (is_directory(&st_1)) {
        printf(1, "Can not copy from directory\n");
    }

    fd1 = open(from, O_RDONLY);
    fd2 = open(to, O_CREATE | O_WRONLY);

    if(fd1 < 0) {
        printf(1, "Cannot open source file\n");
        exit();
    }

    if(fd2 < 0) {
        printf(1, "Cannot open destination file\n");
        exit();
    }

    while((n = read(fd1, buf, sizeof(buf))) > 0) {
        write(fd2, buf, n);
    }

    close(fd1);
    close(fd2);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf(1, "Wrong number of arguments\n");
        exit();
    }
    cp(argv[1], argv[2]);
    exit();
}
