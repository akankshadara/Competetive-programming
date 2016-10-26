#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/**
 * @input A : Integer
 *
 * @Output Integer 0 / 1. Return 0 if the number is not palindrome, else return 1
 */
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

int isPalindrome(int A) {
            int rev = reverse(A);
            if(A==rev && A>=0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
}

int isPalindrome_optimized(int A) {
    int b=A,rev=0,dig;
   while (A > 0)
 {
      dig = A % 10;
      rev = rev * 10 + dig;
      A = A / 10;
 }
  return (b==rev?1:0);
}

void main()
{
    int num;
    scanf("%d", &num);
    int p = isPalindrome(num);
    if(p==1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

}
