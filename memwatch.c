#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *buffer = malloc(128);
    strcpy(buffer, "This memory was manually allocated");
    write(1, buffer, 128);
}
