#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("Integer: %d\n", a);
    printf("Float: %f\n", b);
    printf("Double: %f\n\n", c);
    printf("Size of Integer: %lu\n", sizeof(a));
    printf("Size of Float: %lu\n", sizeof(b));
    printf("Size of Double: %lu\n", sizeof(c));
    return 0;
}
