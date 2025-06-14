#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void reverse(char* start, char* end) {
    char *s = start;

    while (s < end){
        char tmp = *s;
        *s = *end;
        *end = tmp;
        s++;
        end--;
    }
}

int main() {
    char words[] = "pink pony club keep on dancing at the pink pony club";
    reverse(words, (words + strlen(words) - 1)); // reverse all
    char *word_start = words;
    char *word_end = words;
    while (*word_end != '\0') {
        if (*word_end == 32) {
            reverse(word_start, word_end - 1); // reverse word
            word_start = word_end + 1;
        }
        word_end++;
    }
    reverse(word_start, word_end - 1); // last word
    printf("%s", words);
}
