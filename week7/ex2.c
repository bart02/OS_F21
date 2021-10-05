#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;

    printf("Number of array elements: ");
    scanf("%d",&n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d]== %d\n", i, arr[i]);
    }

    free(arr);
}
