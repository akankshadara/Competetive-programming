 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/**
 * @input A : Integer
 *
 * @Output Integer
 */

int trailingZeroes(int A)
{
        int num_5[10] = {0};
        int i=0, count = 0, result = 0;
        int a1 = A;
        while(A>1)
        {
            int d = pow(5, count+1);
            A = A/5;
            num_5[count] = A;
            printf("A: %d, count: %d, divisor: %d num: %d\n", A, count, d, num_5[count]);
            count++;
        }
        for(i=0; i<count; i++)
        {
            result = result + num_5[i];
        }
        return result;
}

void main()
{
    int num;
    scanf("%d", &num);
    int trail = trailingZeroes(num);
    printf("%d", trail);
}
