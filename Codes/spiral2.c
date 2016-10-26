#include<stdio.h>
#include<stdlib.h>

//int **arr;

int k;
void printarr(int** arr,int m , int n);
void spiral(int** arr,int start, int end, int depth, int* result);
int* spiralOrder(int** A, int n11, int n12, int *length_of_array);

void main()
{
    k = 0;
    int **arr;
    int m =3, n =2,i,j,count=1;
    arr = (int**)malloc(m * sizeof(int*));
    for(i=0; i<m ; i++)
    {
        arr[i] = (int*) malloc(n*sizeof(int));
    }
    printarr( arr ,m,n);
    printf("\n \n");
    //printf("check1\n");
   int *length_of_array = (int*)malloc(sizeof(int));
  // printf("check2\n");
    int *result = (int *) malloc((m*n)* sizeof(int));

    result = spiralOrder(arr,m,n, length_of_array);
   // printf("check4\n");
    for(i=0; i<(m*n); i++)
        printf("%d ", result[i]);
}

void printarr( int** arr, int m , int n )
{
    int i,j, count=0;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            arr[i][j]= count++;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("value of i and j %d %d", i , j);
}


void spiral(int** arr ,int start, int end, int depth, int* result)
{
    int i, j;
    i = start;

    if(start>end || start==end){return;}

    for(j=start;j<end;j++)
    {
        //printf("%d ", arr[i][j]);
        result[k++] = arr[i][j];
    }
    //printf("\n");
    j = end-1;
    for(i=start+1; i<depth; i++)
    {
        //printf("%d ", arr[i][j]);
        result[k++] = arr[i][j];
    }
    //printf("\n");
    i = depth-1;
    for(j=end-2; j>start; j--)
    {
        //printf("%d ", arr[i][j]);
        result[k++] = arr[i][j];
    }
   // printf("\n");
    j = start;
    for(i=depth-1; i>start; i--)
    {
        //printf("%d ", arr[i][j]);
        result[k++] = arr[i][j];
    }

    spiral( arr, start+1 , end-1, depth-1, result);
}


int* spiralOrder( int** A, int n11, int n12, int *length_of_array)
 {
	 *length_of_array = n11 * n12; // length of result array
	 int *result = (int *) malloc(n12*n11 * sizeof(int));
	 // DO STUFF HERE
	 spiral(A, 0, n12, n11, result);
	 return result;

}


