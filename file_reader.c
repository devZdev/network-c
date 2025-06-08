#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    char buffer[64];
    ssize_t bytes_read;

    printf("The size of my buffer is %zu", sizeof(buffer));

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        printf("Something read %zd\n", bytes_read);
        write(1, buffer, bytes_read);
    };
    return 0;
}
