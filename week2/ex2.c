#include <stdio.h>
#include <string.h>

int main() {

    char string[1000];
    printf("Input string (no more than 1000 symbols):\n");
    scanf("%s", string);
    printf("Reversed string:\n");
    long len = strlen(string);
    for (long i = len - 1; i >= 0; i--) {
        printf("%c", string[i]);
    }
    printf("\n");

    return 0;

}
