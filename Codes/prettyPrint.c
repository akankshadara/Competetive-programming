#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/**
 * @input A : Integer
 *
 * @Output 2D int array. You need to malloc memory for result 2D array.
 * Fill in number_of_rows as row, number_of_columns as columns
 */
int** prettyPrint(int A, int *number_of_rows, int *number_of_columns)
 {

	int num = 2*A-1;
    *number_of_rows = num;
	*number_of_columns = num;
	int **result = (int **)malloc(num * sizeof(int *));

	int i, j , k;
	for(i=0; i<num; i++)
	{
	    result[i] = (int*)malloc(num*sizeof(int));
	}

   for(j=0; j<A; j++)
   {
        for(i=j; i<num-j; i++)
        {
            result[i][j] = A-j;
            result[j][i] = A-j;
            result[num-1-j][i] = A-j;
            result[i][num-1-j] = A-j;
        }
   }


	return result;

}

void main()
{
    int* rows = (int*)malloc(sizeof(int));
    int* columns = (int*)malloc(sizeof(int));
    *rows = 1;
    *columns = 1;
	printf("Enter a number:\n");
	int A;
	scanf("%d", &A);
	int num = 2*A-1;
	 int **result = (int **)malloc(num * sizeof(int *));
	// printf("check0\n");
	int i, j , k;
	for(i=0; i<A; i++)
	{
	    result[i] = (int*)malloc(num*sizeof(int));
	}
	//printf("check1\n");
	result = prettyPrint(A, rows, columns);
	//printf("check2\n");
	  for(i=0; i<num; i++)
	{
	    for(j=0; j<num;j++)
	    {
	       printf("%d ", result[i][j]);
	    }
	    printf("\n");
	}


}
