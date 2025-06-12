#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void reverse(char *s) {
    char *length_p = s;
    int len = 0;
    while(*length_p != '\0') {
        len++;
        length_p++;
    };

    char *start_p = s;
    char *end_p = s + len - 1;
    while (start_p < end_p) {
        char pocket = *start_p;
        *start_p = *end_p;
        *end_p = pocket;
        start_p++;
        end_p--;
    }
}

int main() {
    char string[] = "what is this world";
    reverse(string);
    printf("%s", string);
}
