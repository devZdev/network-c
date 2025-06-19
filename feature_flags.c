
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FEATURE_LOGIN (1 << 0)
#define FEATURE_UPLOAD (1 << 1)
#define FEATURE_SHARE (1 << 2)
#define FEATURE_DELETE (1 << 3)
#define FEATURE_MODIFY (1 << 4)

void enable_flag (unsigned int* flags, int feature) {
    *flags |= feature;
}

void disable_flag (unsigned int* flags, int feature) {
    *flags &= ~feature;
}

int has_flag(int flags, int feature) {
    return (flags & feature) != 0;
}

void toggle_flag(unsigned int* flags, int feature) {
    *flags ^= feature;
}

void reset_flags(unsigned int* flags) {
    *flags = 0;
}

void print_flags (unsigned int flags) {
    if (flags & FEATURE_LOGIN) puts ("FEATURE LOGIN ENABLED");
    if (flags & FEATURE_UPLOAD) puts ("FEATURE UPLOAD ENABLED");
    if (flags & FEATURE_SHARE) puts ("FEATURE SHARE ENABLED");
    if (flags & FEATURE_DELETE) puts ("FEATURE DELETE ENABLED");
    if (flags & FEATURE_MODIFY) puts ("FEATURE MODIFY ENABLED");
}

int main() {
    unsigned int flags = 0;
    enable_flag(&flags, FEATURE_LOGIN);
    reset_flags(&flags);
    toggle_flag(&flags, FEATURE_SHARE);
    disable_flag(&flags, FEATURE_SHARE);
    enable_flag(&flags, FEATURE_MODIFY);
    has_flag(flags, FEATURE_MODIFY);
    print_flags(flags);
}

