#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char buffer[64];
    ssize_t bytes_read;

    while ((bytes_read = read(0, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read);
    }

    return 0;
}
