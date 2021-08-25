#include <stdio.h>

void print(char c, int qty) {
    for (int i = 0; i < qty; ++i) {
        printf("%c", c);
    }
}

int main(int argc, char **argv) {
    int n;
    sscanf(argv[1], "%d", &n);

    printf("Main figure:\n");
    for (int i = 1; i <= n; i++) {
        print(' ', n - i);
        print('*', 2*i - 1);
        printf("\n");
    }

    printf("\nFirst additional figure:\n");
    for (int i = 1; i <= n; i++) {
        print('*', i);
        printf("\n");
    }

    printf("\nSecond additional figure:\n");
    for (int i = 1; i <= (n+1); i++) {
        if (i < (n+1)/2 +1)
            print('*', i);
        else
            print('*', (n+1)-i);
        printf("\n");
    }

    printf("\nThird additional figure:\n");
    for (int i = 1; i <= n; i++) {
        print('*', n);
        printf("\n");
    }

    return 0;
}
