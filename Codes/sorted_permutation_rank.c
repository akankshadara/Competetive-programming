#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/**
 * @input A : String termination by '\0'
 *
 * @Output Integer
 */

//%1000003 to check overflow
 int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return(num * factorial(num - 1)%1000003);
    }
}



int findRank(char* A)
{
    int i=0, length =0, j=0;
    int rank = 0;
    while(A[i]!='\0')
    {
        i++;
        length++;
    }
    if(length==1)
    {
        return 1;
    }
    //int num_strings = factorial(length);
    int* rank_array = (int*)malloc(length*sizeof(int));

    for(i=0; i<length; i++)
    {
        int x =  A[i];
        int r = 1;
        for(j=0; j<length; j++)
        {
            if(A[j]<x)
            {
                r++;
            }
        }
        rank_array[i] = r;
    }

    for(i=0; i<length; i++)
    {
          printf("%c %d\n",A[i], rank_array[i]);
    }

    int n = (rank_array[0]-1);
    rank =  (n*factorial(length-1)%1000003 + findRank(A+1));
    printf("r %d\n", rank);
    return rank%1000003;
}

void main()
{
    int rank = findRank("ZCSFLVHXRYJQKWABGT");
    printf("\nRank: %d ", rank);
}
