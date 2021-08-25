#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char **argv) {
    int one, two;
    printf("Input first integer: ");
    scanf("%d", &one);
    printf("Input second integer: ");
    scanf("%d", &two);

    printf("\nBefore swap: one = %d, two = %d.", one, two);

    swap(&one, &two);

    printf("\nAfter swap: one = %d, two = %d.\n", one, two);

    return 0;
}
