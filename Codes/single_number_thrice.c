#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */

int singleNumber(const int* A, int n1)
{
    //perform XOR for each number
    int i;
    int first = 0, second = 0;
    for(i=0; i<n1; i++)
    {
       first = (first^A[i]) & ~second;
       second = (second^A[i]) & ~first;
    }
    return  first;
}
void main()
{
    //int size;
    //scanf("%d", &size);

     int array[7] = {2, 2, 2, 3, 3, 3, 7 };
   //int * array = (int*)malloc(size*sizeof(int));
    int ans = singleNumber(array,7);
    printf("\n%d", ans);

    return;
    /*int i;
    for(i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }*/

}


