#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/**
 * @input A : Integer
 *
 * @Output Integer
 */
int numSetBits(unsigned int A)
{
        int i, count = 0;
        for(i=0; i<32; i++)
        {
            unsigned int b = 01;
            if(A&b == 1)
            {
                count++;
            }
            //do right shift A&01 ->gives number of 1s
            A = A>>1;
            //A>>1 will not work
        }
        return count;
}

void main()
{
    unsigned int num;
    scanf("%d", &num);
    int ans = numSetBits(num);
    printf("%d\n", ans);
}
