#include<stdio.h>


void xorSwap (int *x, int *y) {
     if (x != y) {
         *x ^= *y;
         *y ^= *x;
         *x ^= *y;
     }
 }
int main()
{
    int a = 2, b = 7;

    a = a^b;
    b = b^a;
    a = a^b;
    printf("a %d b %d", a, b);
    return 0;
}
