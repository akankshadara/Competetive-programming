#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPower(int A)
{
    int i, p;
       for(i=1; i<=sqrt(A); i++)
       {
               for(p=2; p<=50; p++)
               {
                    if(pow(i, p)==A)
                    {
                        return 1;
                    }
               }
       }
       return 0;

}

void main()
{
    int A ;
    scanf("%d", &A);
    int p = isPower(A);
    if(p == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}
