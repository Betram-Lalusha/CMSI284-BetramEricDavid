
#include <stdio.h>

int main() {
    unsigned int i = 1;
    char *c = (char*)&i;
    if(*c) {
        printf("Little endian machine\n");
    } else {
        printf("Big endian machine\n");
    }
    return 0;
}