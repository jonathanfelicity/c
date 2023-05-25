#include <stdio.h>
#include <string.h>

struct User {
    char email[100];
    char password[100];
};

int main(void) {
    struct User johndoe;
    strncpy(johndoe.email, "johndoe@fake.com", sizeof(johndoe.email) - 1);
    strncpy(johndoe.password, "123@", sizeof(johndoe.password) - 1);

    johndoe.email[sizeof(johndoe.email) - 1] = '\0';       // Ensure null termination
    johndoe.password[sizeof(johndoe.password) - 1] = '\0'; // Ensure null termination

    printf("Email: %s\n", johndoe.email);
    printf("Password: %s\n", johndoe.password);

    return 0;
}
