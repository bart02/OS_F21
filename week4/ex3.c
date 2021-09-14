#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;
        system(input);
    }

    return 0;
}