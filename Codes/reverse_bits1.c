#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/**
 * @input A : Integer
 *
 * @Output Integer
 */


 unsigned int reverse1(unsigned int A)
 {
    unsigned int rev=0,m=31;
    while(A)
    {
        if(A&1)
            rev=rev|1<<m;
            //printf("%u \n", A);
        A>>=1;
        m--;
    }
    return rev;
}

 void main()
 {
     printf("Reverse: %u",reverse1(11));
 }
