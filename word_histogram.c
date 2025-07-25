#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* make_word(char* start, size_t length) {
    char* buffer = malloc(length + 1);
    for (int i =0; i < length; i++) {
        buffer[i] = start[i];
    }
    buffer[length] = '\0';
    return buffer;
}

int main() {
    char text[] = "Maybe if we go to New Jersey we could buy a couch";
    int counts[256] = {0};
    char* p_words[256] = {0};
    char* t = text;
    char* word_start = text;
    char* word_end = text;

    while (1) {
        if (*t == 32 || *t == '\0') {
            word_end = t - 1;
            size_t length = word_end - word_start + 1;
            char* buffer = make_word(word_start, length);

            int found = 0;
            for (int j = 0; j < 256; j++) {
                if (p_words[j] != NULL && ((strcmp(p_words[j], buffer)) == 0)) {
                    counts[j]++;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                for (int k = 0; k < 256; k++) {
                    if (p_words[k] == NULL) {
                        p_words[k] = buffer;
                        counts[k] = 1;
                        break;
                    }
                }
            }

            word_start = t + 1;
        }

        if (*t == '\0') {
            break;
        }

        t++;
    }

    for (int m = 0; m < 256; m++) {
        if (p_words[m] != NULL) {
            printf("\n%s : %d", p_words[m], counts[m]);
        }
    }

    for (int l = 0; l < 256; l++) {
        if (p_words[l] != NULL) {
            free(p_words[l]);
        }
    }
}

