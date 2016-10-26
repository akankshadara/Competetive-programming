#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* findDigitsInBinary(int A) {
	// SAMPLE CODE
	/*
	 * char* result = (char *)malloc(100 * sizeof(char));
	 * // DO STUFF HERE
	 * return result;
	 */

	int *result1 = (int *) malloc(100 * sizeof(int));
	char* result = (char *)malloc(100 * sizeof(char));
    int i=0, count = 0, j=0;

     if(A==0)
     {
        result[i] = '0';
         return result;
     }

    while(A!=0)
    {
        int rem = A%2;
        A = A/2;
        result1[count] = rem;
        //count++;
       // printf("%d", result[count]);
        count++;
    }
    for(i=count-1; i>=0; i--)
    {
      //printf("%d", result1[i]);
       result[j] = '0' +  result1[i];
       printf("%c ", result[j]);
       j++;
    }
    return result;
}

char* DecToBaseN(int A, int base) {
	// SAMPLE CODE
	/*
	 * char* result = (char *)malloc(100 * sizeof(char));
	 * // DO STUFF HERE
	 * return result;
	 */

	int *result1 = (int *) malloc(100 * sizeof(int));
	char* result = (char *)malloc(100 * sizeof(char));
    int i=0, count = 0, j=0;

     if(A==0)
     {
        result[i] = '0';
         return result;
     }

    while(A!=0)
    {
        int rem = A%base;
        A = A/base;
        result1[count] = rem;
        //count++;
       //printf("%d", result[count]);
        count++;
    }
    for(i=count-1; i>=0; i--)
    {
      //printf("%d", result1[i]);
       result[j] = '0' +  result1[i];
      printf("%c ", result[j]);
       j++;
    }
    return result;
}
void main()
{


      char *result = (char *) malloc(100 * sizeof(char));
        int i, A = 3221225472;

       result = findDigitsInBinary(A);
      // printf()

  //result = DecToBaseN(3221225472,10);

}
