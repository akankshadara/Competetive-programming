#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Reverse digits of an integer.
//Return 0 if the result overflows and does not fit in a 32 bit signed integer
//for negative too
int reverse(int A)
{
    int digits = 0;
    int A_temp = abs(A);
    while(A_temp!=0)
    {
        A_temp = A_temp/10;
        digits++;
    }
    //printf("%d", digits);

    A_temp = abs(A);
    int *num = (int*)malloc(digits*sizeof(int));
    int i, n, rev = 0, count=0;

     for(i=0; i<digits; i++)
    {
        n = A_temp%10;
        //printf("%d\n", n);
        A_temp = A_temp/10;
        //printf("%d  %d\n", n, A_temp);
        num[count++] = n;
    }

//1000000003
    for(i=0; i<digits; i++)
    {
        rev = rev + (num[i]*pow(10,digits-1-i));
    }

    int out;
    if(A>0)
    {
        out = rev;
    }
    else
    {
        out = (-1*rev);
    }
    if(A>0 && out>0)
    {
        return out;
    }
    else if(A<0 && out<0)
    {
        return out;
    }
    else
    {
        return 0;
    }
}
void main()
{
    int A;
    scanf("%d", &A);
    int rev = reverse(A);
    printf("%d", rev);
}
