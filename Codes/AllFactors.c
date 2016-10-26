/**
 * @input A : Integer
 *
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
 #include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* allFactors(int A, int *length_of_array) {
	// SAMPLE CODE
        /*
         * *length_of_array = 1000; // length of result array
         * int *result = (int *) malloc(*length_of_array * sizeof(int));
         * // DO STUFF HERE. NOTE: length_of_array is inaccurate in this example.
         * return result;
         */
         int i, flag=0, count = 0;
         int sq = sqrt(A);
         if(sq*sq == A)
         {
             flag = 1;
         }
         int *result = (int *) malloc(1000 * sizeof(int));
         for(i=1; i<=sq; i++)
         {
             if(A%i == 0)
                {
                    result[count] = i;
                    count++;
                }
         }

        if(flag == 1)
        {
             int temp = count-2;
            for(i=temp; i>=0; i--)
                 {
                     result[count++] = (A/result[i]);
                 }
        }
        else
        {
             int temp = count-1;
             for(i=temp; i>=0; i--)
                 {
                     result[count++] = (A/result[i]);
                 }
        }
           *length_of_array = count;
         return result;
}
int* allFactors_optimized(int A, int *length_of_array) {
         int *res = (int *) malloc(10000 * sizeof(int));
         int i,x=0;
         for(i=1;i<=(int)sqrt(A);i++)
         {
             if(A%i==0)
             res[x++]=i;
         }
         int y=x;
         for(i=x-1;i>=0;i--)
         {
             if(A%res[i]==0 && res[i]!=(A/res[i]))
             res[y++]=A/res[i];
         }
         *length_of_array=y;
         return res;
}

void main()
{
    int A;
    scanf("%d", &A);
    int* length_of_array = (int*)malloc(sizeof(int));
    *length_of_array = 100;
    int * result = (int*)malloc(100*sizeof(int));
    result = allFactors(A, length_of_array);
}
