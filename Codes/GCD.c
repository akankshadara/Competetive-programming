#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int gcd(int A, int B)
{
    if(A==0 && B!=0)
    {
        return B;
    }
    if(A==0 && B==0)
    {
        return 0;
    }
    if(A>B)
    {
        return gcd(B, A);
    }
    int rem = 1, q, temp;

    while(rem!=0)
    {
        temp = A;
        q = B/A;
        rem = B%A;
        B = A;
        A = rem;
    }
    return temp;
}
int gcd_optimized(int A, int B)
{
      if ( A==0 )
      return B;
      else
      return gcd ( B%A, A );
}
void main()
{
    printf("Enter 2 numbers:\n");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    int g = gcd(a,b);
    printf("\ngcd is: %d", g);
}
