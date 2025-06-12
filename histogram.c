#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char input[] = "Once there was a way to get back home";
    printf("Input: %s", input);
    unsigned char *p = (unsigned char *)input;

    unsigned int histogram[256] = {0};
    printf("histogram[255]: %d", histogram[255]);
    while(*p != '\0') {
        histogram[*p]++;
        p++;
    }

    for (int i = 0; i < 256; i++) {
        if (histogram[i] > 0) {
            printf("\n%c appeared %d times", i, histogram[i]);
        }
    }
}
