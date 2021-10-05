#include <stdio.h>
#include <stdlib.h>

#define SIZE 15
#define MAX_LENGTH 15

int main() {
    char **s = malloc(SIZE * sizeof(char *));
    for (int i = 0; i < SIZE; i++) {
        s[i] = malloc(MAX_LENGTH * sizeof(char));
    }

    char foo[] = "Hello World";

    *s = foo;
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    return(0);
}
