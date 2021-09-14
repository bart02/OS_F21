#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char input[1000];
    char temp[1000];

    while (1) {
        scanf("%[^\n]", input);
        fgets(temp,1000,stdin);
        if (strcmp(input, "exit") == 0) break;
        fork();
        system(input);
    }

    return 0;
}