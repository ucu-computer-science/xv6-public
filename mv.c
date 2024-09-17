#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf(1, "Usage: mv <from_file> <to_file>\n");
        exit();
    }
    
    if(link(argv[1], argv[2]) < 0) {
        printf(1, "Cannot link first path to second\n");
        exit();
    }

    if(unlink(argv[1]) < 0) {
        printf(1, "Cannot unlink file from source path\n");
        exit();
    }

    exit();
}
