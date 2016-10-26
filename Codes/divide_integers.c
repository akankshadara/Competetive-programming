#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define INT_MAX 99999999999999999
/**
 * @input dividend : Integer
 * @input divisor : Integer
 *
 * @Output Integer
 */
 //implementing the division algo in DD
int divide(int dividend, int divisor)
{
        int A = 0, Q = dividend, M = divisor;
        /*int a = divisor;
        while(divisor<dividend)
        {
            divisor = divisor + a;
            ans++;
        }
        return ans;*/
        int bits = 0, i=0, flag = 1;
        while(flag==1)
        {
            if(divisor>pow(2, i-1) && divisor<=pow(2,i))
            {
                flag = 0;
            }
            i++;
        }
        printf("%d i\n",i);
        bits = i;
        for(i=0; i<bits; i++)
        {
            A = A<<1;
            Q = Q<<1;
            A = A-M;
            printf("A: %d ", A);
            if(A<0)
            {
                if(Q%2!=0)
                {
                    Q = Q-1;
                    A = A+M;
                }
                printf("Q: %d\n", Q);
            }
            else if(A>=0)
            {
                if(Q%2==0)
                {
                    Q = Q+1;
                }
                printf("Q: %d\n", Q);
            }
        }

        return Q;
}
int divide1(int a,int b)
{
    if(!b)
        return INT_MAX;

    long long c=(long long)a/b;
    printf("%d", c);

    if(c>=0 && c<=INT_MAX)
        return c;
    if(c<0)
        return c;

    return INT_MAX;
}
int divide2(int dividend,int divisor)
{
    long long  n = dividend;
    int m = divisor;
    //storing the sign of the quotient
    int sign = 1;
    if(n^m == 1)
    {
        sign = -1;
    }
    //removing signs
    n = abs(n);
    m = abs(m);
    long long A = 0, q=0;
    int i;
    for(i=31; i>=0; i++)
    {
        if((A + (m<<i))  <=n )
        {
            A = A + (m<<i);
            q |= 1LL << i;
        }
    }
    if(sign<0)
        q = -q;

    return q;
}
void main()
{
    int dividend, divisor;
    printf("Enter dividend:\n");
    scanf("%d", &dividend);
    printf("Enter divisor:\n");
    scanf("%d", &divisor);

    int ans = divide1(dividend, divisor);
    printf("\nQuotient: %d", ans);
}
