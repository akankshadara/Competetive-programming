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

void swap(int* a, int* b)
{
            int temp;
            temp = *a;
            *a = *b;
            *b= temp;
            return;
}

void bubbleSort(int A[], int n)
{
    int i,j;
    for(j=n-1; j>=0; j--)
    {
        for(i=0; i<j; i++)
            {
                if(A[i] > A[i+1])
                    swap(&A[i], &A[i+1]);
            }
    }
}


int findRank(char* A)
{
        int i=0, length =0, j=0;
        int rank = 0;
        //finding lenth of string
        while(A[i]!='\0')
        {
            i++;
            length++;
        }
        //base case for recursion
        if(length==1)
        {
            return 1;
        }
        //initialize rank array and sorted rank array
        int* rank_array = (int*)malloc(length*sizeof(int));
        int* rank_sorted = (int*)malloc(length*sizeof(int));
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
            rank_sorted[i] = r;
        }

       /* for(i=0; i<length; i++)
        {
              printf("\n%c %d",A[i], rank_array[i]);
        }*/
        //sorting
        bubbleSort(rank_sorted, length);
       // printf("\nsorted");

        int* occurence = (int*)malloc(length*sizeof(int));

        for(i=0; i<length; i++)
        {
            occurence[i] = 0;
        }
        int unique_length = 1,k=0, z;
        //find length of occurrence array
        for(i=0; i<length;)
        {
            int count = 1;
            int x = rank_sorted[i];
            z=i;
            while(x==rank_sorted[z+1])
            {
                z++;
                count++;
            }
            occurence[k++] = count;
            i=i+count ;
        }
        unique_length = k;
       // printf("\nunique length: %d", unique_length);
        int fact = 1;
         fact = factorial(length-1);

        for(j=0; j<unique_length; j++)
        {
            fact = fact/factorial(occurence[j]);
           // printf("\n fact %d", fact);
        }
        int ans=0;
        int y=0;

          //  printf("hey\n");
         i = 0;
          int first_letter = rank_array[0];
            while( first_letter != rank_sorted[i])
            {
                int temp = occurence[y];
                 i = i + occurence[y++];
                 ans = ans + fact*temp;
            }

        printf("\n%d", ans);
        rank = ans + findRank(A+1);
       // printf("r %d\n", rank);
        return rank%1000003;
}

void main()
{
    int rank = findRank("AKANKSHAAA");
    printf("\nRank: %d ", rank);
}

