#include<stdio.h>
#include<stdlib.h>

//int **arr;

void printarr(int** arr,int m , int n);
void spiral(int** arr,int start, int end, int depth);
void main()
{
    //int arr2[5][5] ={ [1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5],[1,2,3,4,5]};
    int **arr;
    int m = 5, n = 6,i,j,count=1;
    arr = (int**)malloc(m * sizeof(int*));
    for(i=0; i<m ; i++)
    {
        arr[i] = (int*) malloc(n*sizeof(int));
    }
    printarr( arr ,m,n);
    printf("\n \n");
    spiral(arr,0,n,m);
}

void printarr( int** arr, int m , int n )
{
    int i,j, count;
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

void spiral(int** arr ,int start, int end, int depth)
{
    int i, j;
    i = start;

    if(start>end){return;}

    for(j=start;j<end;j++)
    {
        printf("%d ", arr[i][j]);
    }
    //printf("\n");
    j = end-1;
    for(i=start+1; i<depth; i++)
    {
        printf("%d ", arr[i][j]);
    }
    //printf("\n");
    i = depth-1;
    for(j=end-2; j>start; j--)
    {
        printf("%d ", arr[i][j]);
    }
   // printf("\n");
    j = start;
    for(i=depth-1; i>start; i--)
    {
        printf("%d ", arr[i][j]);
    }

    spiral( arr, start+1 , end-1, depth-1);
}




