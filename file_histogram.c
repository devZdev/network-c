#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    /*
    * f
* Open a file
* Create a buffer
* Read the file into a buffer
* Create an integer data structure where each byte is initialized with zero
* read the buffer with the file contents and print out histogram style
*
*
*
* */
    int fd = open("test.txt", O_RDONLY);
    char buffer[64];
    ssize_t bytes_read;
    size_t histogram[256] = {0};

    while((bytes_read = read(fd, buffer, sizeof(buffer)))){
        for(size_t i = 0; i < bytes_read; i++) {
            histogram[(unsigned char)buffer[i]]++;
        };
    };

    for (int j = 0; j < 256; j++) {
        if (histogram[j] != 0) {
            printf("\n%c appeared %zu times.", j, histogram[j]);
        }
    }
}
