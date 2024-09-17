#include "types.h"
#include "user.h"
#include "fcntl.h"

void cp(char *from, char *to) {
    int fd1, fd2, n;
    char buf[512];

    if((fd1 = open(from, O_RDONLY)) < 0) {
        printf(1, "cp: cannot open %s\n", from);
        exit();
    }

    if((fd2 = open(to, O_CREATE | O_WRONLY)) < 0) {
        printf(1, "cp: cannot open %s\n", to);
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

