#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *vowel_uppercaser(char *str) {
    char *p = str;
    while(*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
            *p = *p - 32;
        }
        p++;
    }
    return str;
}

int main() {
    char str[] = "when i was a little boy, i looked under the stairs";
    char *p = str;
    vowel_uppercaser(str);
    while (*p != '\0') {
        printf("%c", *p);
        p++;
    }
    return 0;
}
