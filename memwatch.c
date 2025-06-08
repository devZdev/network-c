#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t buffer_size_a = 128;
    size_t buffer_size_b = 64;
    size_t total_allocated = 0;
    size_t total_freed = 0;


    char *a_buffer = malloc(buffer_size_a);
    char *b_buffer = malloc(buffer_size_b);

    if (a_buffer == NULL || b_buffer == NULL) {
        fprintf(stderr, "\nNo memory allocated, exiting!");
        return 1;
    }

    strcpy(a_buffer, "\nThis memory was manually allocated to buffer a");
    total_allocated += buffer_size_a;

    strcpy(b_buffer, "\nThis memory was manually allocated to buffer b");
    total_allocated += buffer_size_b;

    printf(
        "\nWe allocated %zd bytes of memory",
        total_allocated
    );

    write(1, a_buffer, strlen(a_buffer));
    write(1, b_buffer, strlen(b_buffer));

    free(a_buffer);
    total_freed += buffer_size_a;

    free(b_buffer);
    total_freed += buffer_size_b;

    printf(
        "\nWe freed %zd bytes of memory" ,
        total_freed
    );
    return 0;
}
