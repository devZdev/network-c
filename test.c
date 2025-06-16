#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char some_string[] = "The wall";
    *some_string[some_string + 1] = 12;
    printf("%s", some_string);
//    for (int i =0; i < 10; i++) {
//        int len = strlen(some_string);
//        some_string[len + i] = i;
//    }
    printf("some string: %s", some_string);
}
