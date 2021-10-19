#include <stdio.h>

#define TYPE unsigned short
#define NUMBER_BITS (sizeof(TYPE) * 8)

void bin(TYPE n)
{
    TYPE i;
    for (i = 1 << (NUMBER_BITS - 1); i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

typedef struct Page {
    TYPE counter; // 2 bytes = 16 bits
    int num_page;
} Page;

int main() {
    FILE* file = fopen("/Users/artembatalov/CLionProjects/OS/input.txt", "r");
    if (file == NULL)
    {
        printf("No such file");
        return -1;
    }

    int n;
    printf("Page number: ");
    scanf("%d", &n);

    Page pages[n];
    for (int i = 0; i < n; i++) {
        pages[i].counter = 0;
        pages[i].num_page = -1;
    }

    int pointer = 0;

    int hits = 0;
    int misses = 0;

    int page;
    while (fscanf(file, "%d", &page) == 1) {
        if (page == -1) break;

        int stored = 0;

        for (int i = 0; i < n; i++) {
            pages[i].counter >>= 1;
            if (page == pages[i].num_page) {
                pages[i].counter |= 1 << (NUMBER_BITS - 1);
                hits++;
                stored = 1;
            }
        }

        if (!stored) {
            if (pointer < n) {
                pages[pointer].num_page = page;
                pages[pointer].counter = 1 << (NUMBER_BITS - 1);
                pointer++;
            } else {
                TYPE min_counter = pages[0].counter;
                int min_i = 0;
                for (int i = 0; i < n; i++) {
                    if (pages[i].counter < min_counter) {
                        min_counter = pages[i].counter;
                        min_i = i;
                    }
                }

                pages[min_i].num_page = page;
                pages[min_i].counter = 1 << (NUMBER_BITS - 1);
            }
            misses++;
        }
        printf("Page: %d\n", page);
        for (int i = 0; i < n; i++) {
            printf("Index: %d\tPage: %d\tCounter_DEC: %d \t\tCounter_BIN: ", i, pages[i].num_page,
                   pages[i].counter);
            bin(pages[i].counter);
            printf("\n");
        }
        printf("\n");
    }

    fclose(file);

    printf("Hit ratio %.3f\nMiss ratio %.3f\n", (hits*1.0f)/(hits + misses), (misses*1.0f)/(hits + misses));

    return 0;
}
