#include <stdio.h>
#define SIZE 100000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[SIZE];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    bubble_sort(a, n);

    printf("\nAfter sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;

}
