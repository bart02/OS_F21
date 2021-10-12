#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

#define SIZE (1024 * 1024 * 1024)

int main() {
    for (int i = 0; i < 30; i++) {
        void *s = malloc(SIZE);
        memset(s, 0, SIZE);
        sleep(1);
    }

    return(0);
}

// 'si' and 'so' fields show amount of memory Swapped In and Out.
// My machine has 24G of Physical memory, so I define allocation of 30 1G blocks.
// If swap is off, OS killed my program, when it allocated all free memory.
// If I add swap, after allocation all physical memory, it use swap, and 'si' and 'so' fields are greater than 0.
// But wile using swap freezes often appear, because important OS programs' memory are copied to swap,
// and hard drive is too slow.
