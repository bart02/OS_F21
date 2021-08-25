#include <stdio.h>

void print(char c, int qty) {
    for (int i = 0; i < qty; ++i) {
        printf("%c", c);
    }
}

int main(int argc, char **argv) {
    int n;
    sscanf(argv[1], "%d", &n);
    for (int i = 1; i <= n; i++) {
        print(' ', n - i);
        print('*', 2*i - 1);
        printf("\n");
    }

    return 0;
}
