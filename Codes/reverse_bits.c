#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/**
 * @input A : Integer
 *
 * @Output Integer
 */
 //swap bits at ith and jth positions
/* unsigned int swapBits(unsigned int A, int p1, int p2)
 {
     unsigned int x = (A>>p1)&1;
     unsigned int y = (A>>p2)&1;

     unsigned int z = (x^y);
     z = (z<<p1) || (z<p2);
     z = A^z;
     return z;
 }*/
 unsigned int swapBits(unsigned int n, unsigned int p1, unsigned int p2)
{
    /* Move p1'th to rightmost side */
    unsigned int bit1 =  (n >> p1) & 1;

    /* Move p2'th to rightmost side */
    unsigned int bit2 =  (n >> p2) & 1;

    /* XOR the two bits */
    unsigned int x = (bit1 ^ bit2);

    /* Put the xor bit back to their original positions */
    x = (x << p1) | (x << p2);

    /* XOR 'x' with the original number so that the
       two sets are swapped */
    unsigned int result = n ^ x;
    return result;
}
unsigned int reverse(unsigned int A)
 {
     int i, j, ans;
    unsigned int left_bit, right_bit;
     unsigned int a1 = A;
     for(i=1; i<16; i++)
     {
         int left = (0x80000000>>i);
         int right = (0x00000001<<i-1);
         left_bit = A&left;
         right_bit = A&right;
         //A = a1;
         printf("left: %d right: %d\n", left, right);
          printf("left bit: %d right bit: %d\n", left_bit, right_bit);
         printf("%u\n", A);
         if(left_bit!=right_bit)
         {
                A = A^(0x80000000>>i);
                A = A^(0x00000001<<i);
                ans = A;
                printf("check\n");
         }
         A= a1;
     }
     printf("A: %u", ans);

    return ans;
 }

void main()
{
    unsigned int num;
    scanf("%d", &num);
    unsigned int ans = reverse(num);
   printf("%u\n", ans);
}
