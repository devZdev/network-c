#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t my_strlen(const char *s) {
    size_t len = 0;

    while(s[len] != '\0'){
        len++;
    }
    return len;
}

char *str_multiply(const char *str, const int multiplier) {
    size_t len = my_strlen(str);

    char *buffer = malloc(len * multiplier + 1);
    char *p = buffer;

    for(int i; i < multiplier; i++) {
        memcpy(p, str, len);
        p += len;
    }
    *p = '\0';
    return buffer;
}

int main() {
    char *message =
        "Once, out in the rain. I was able to strangle my shadow and shackle the chain"
        "What, what will you do? Is it safe to play god in the garden and king of the zoo?"
        "Holes, they need to be filled. Positions available, yet some are quite hard to get out of or in";

    const int multiplier = 300000;
    char *bigstring = str_multiply(message, multiplier);

    clock_t start = clock();
    size_t std_len = strlen(bigstring);
    clock_t end = clock();
    double duration = (double)(end - start)/ CLOCKS_PER_SEC;
    printf("\nStandard string length algo: %f seconds.", duration);

    clock_t my_start = clock();
    size_t my_len = my_strlen(bigstring);
    clock_t my_end = clock();
    double my_duration = (double)(my_end - my_start)/ CLOCKS_PER_SEC;
    printf("\nMy string length algo: %f seconds.", my_duration);

    printf("\nStandard string length is %zu", std_len);
    printf("\nMy string length is %zu", my_len);

    free(bigstring);
    return 0;
}
