#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n = rand() % 100;

    int pid = fork();
    if (pid == 0) {
        printf("Hello from child [%d - %d]\n", pid, n);
    }
    else {
        printf("Hello from parent [%d - %d]\n", pid, n);
    }

    return 0;
}
