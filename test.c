#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ (1 << 0)
#define WRITE (1 << 1)
#define EXECUTE (1 << 2)
#define DELETE (1 << 3)

void print_bits (unsigned int x) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

int main() {
    unsigned int a = 0b0011;
    unsigned int b = 0b0000;

//    print_bits(a & b);
//    print_bits(a | b);
//    print_bits(a ^ b);
//    print_bits(~b);
//    print_bits(b << 2);
//    print_bits(b >> 2);
    //    enable one flag
    //    disable one flag
    //    set all permissions in one go
    //    revoke all permissions in one go
    //    set multiple
    //    remove multiple

    unsigned int permissions = 0;
    unsigned int add_all_permissions = permissions;
    add_all_permissions |= READ | WRITE | EXECUTE | DELETE;

    unsigned int revoke_all_permissions = add_all_permissions;
    revoke_all_permissions &= READ & WRITE & EXECUTE & DELETE;

    unsigned int add_two = permissions;
    add_two |= READ | WRITE;

    unsigned int remove_one = add_two;
    remove_one &= ~READ;

    print_bits(add_all_permissions);
    print_bits(revoke_all_permissions);
    print_bits(add_two);
    print_bits(remove_one);
    print_bits(a & b);
}

