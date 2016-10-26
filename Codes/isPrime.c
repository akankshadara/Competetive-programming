#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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


void main()
{
    int A = 2;
    int prime = isPrime(A);
    if(prime == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}
