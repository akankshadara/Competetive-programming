#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/**
 * @input A : Integer
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

int isPrime(int A) {

    if(A==1)
        return 0;

      int i, sq = sqrt(A);
      for(i=2; i<=sq; i++)
         {
             if(A%i == 0)
                {
                    return 0;
                }
         }
    return 1;
}

int* primesum(int A, int *len1)
{
     int* result = (int*)malloc(2*sizeof(int));
     int i, j;
     if(A==4)
     {
         result[0] = 2;
         result[1] = 2;
         return result;
     }

     else
     {
         for(i=A-1; i>0; i=i-2)
        {
             if(isPrime(i)==1)
             {
                int n = A - i;
                if(isPrime(n)==1)
                {
                    result[0] = n;
                    result[1] = i;
                    //printf("%d %d", n, i);
                    return result;
                }
             }
         }
     }

}
void main()
{
    int A;
    scanf("%d", &A);
      int* len1 = (int*)malloc(sizeof(int));
    *len1 = 0;
    int* result = (int*)malloc(2*sizeof(int));
    result = primesum(A, len1);
    printf("[%d,%d]", result[0],result[1]);
}
