#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    unsigned char buffer[64];
    ssize_t bytes_read;
    size_t histogram[256] = {0};

    while((bytes_read = read(fd, buffer, sizeof(buffer)))){
        for(size_t i = 0; i < bytes_read; i++) {
            histogram[buffer[i]]++;
        };
    };

    for (int j = 0; j < 256; j++) {
        if (histogram[j] != 0) {
            printf("\n%c appeared %zu times.", j, histogram[j]);
        }
    }
}
