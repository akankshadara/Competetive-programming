#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * @input A : Integer
 *
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */

int* sieve(int A, int *length_of_array) {
	// SAMPLE CODE
        /*
         * *length_of_array = A; // length of result array
         * int *result = (int *) malloc(*length_of_array * sizeof(int));
         * // DO STUFF HERE. NOTE : length_of_array is inaccurate here.
         * return result;
         */
          int isPrime, j, i;
         int count = 0;
         int sq = sqrt(A);
         int *result = (int *) malloc(20* sizeof(int));

        for(i=2; i<A; i++)
          {

                isPrime = 1;

                for(j=2; j<=i/2; j++)
                {

                    if(i%j==0)
                    {
                        isPrime = 0;
                        break;
                    }
                }

                if(isPrime==1)
                {
                    result[count++] = i;
                }
            }




         *length_of_array = count;
         return result;
}


