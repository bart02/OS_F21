#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* foo(void* p){
    usleep(10);
    printf("Hello from thread: ");
    printf("%i\n", * (int*)p);

    free(p);

    pthread_exit(NULL);
}

int main(void){
    int n;
    printf("Enter number of threads: ");
    scanf("%d", &n);
    for (int j = 0; j < n; j++)  {
        int * inp = (int*) malloc(sizeof(int));
        *inp = j;
        pthread_t thread;
        if (pthread_create(&thread, NULL, foo, inp)) {
            printf("ERROR\n");
            return -1;
        } else {
            printf("CREATED %d\n", j);
        }
        pthread_join(thread, NULL);
    }
}