#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fact(int x)
{
    if(x==1 || x==0)
        return 1;
    else
        return x*fact(x-1)%1000003;     // %1000003 checks for overflow
}

 int findRank( char *A)
 {
    int i=0,j, ans =0, len=0 ,x;
    char* num;
    num=A;
    while(num[i]!='\0')     //finding length of string
    {
        len++;
        i++;
    }

    if(len == 1)        //base case for recursion.
        return 1;

    int* rank_arr = (int*)malloc(len*sizeof(int));      // rank_arr stores the ranks of each letter
    int count=0;
    for(i=0;i<len;i++)                                  //finding the rank of the each letter
    {
        x= num[i];
        count = 0;
        for(j=0;j<len;j++)
        {
            if(num[j] < x)
                count++;
        }
        rank_arr[i] = count+1;
    }

    int* sorted_arr = (int*)malloc(len*sizeof(int));
    for(i=0;i<len;i++)                                  // copying the array of sorting
        sorted_arr[i] = rank_arr[i] ;


    for(i=0;i<len;i++)                                  // sorting the rank array.
    {
        for(j=0;j<len;j++)
        {
            if(sorted_arr[i]<sorted_arr[j])
            {
                x = sorted_arr[i];
                sorted_arr[i] = sorted_arr[j];
                sorted_arr[j] = x ;
            }
        }
    }


                                            //finding occurence of each letter .
    int occurence_arr[len] ;                // and storing in occurrence_array.
    int occur ;
    j= 0;

    for(i=0;i<len;i++)                      // initializing the array with 0.
        {
            occurence_arr[i] = 0;
        }


    int k= 0;           //important loop... final value of k gives the number of unique letters.
    for(i=0;i<len;i = i)    // making the occurrence_arr

    {                                                   //tools
        x = sorted_arr[j] ;                             //1.) rank array.
        occur = 1;                                      //2.) sorted array.
        while(sorted_arr[j+1] == x)                     //3.) occurrence array.
        {
            occur++;
            j++;
        }
        occurence_arr[k] = occur;
        j++;
        k++;
        i = i+ occur ;

    }
   // printf("%d \n", occurrence_arr[2]);
   //  printf("checkpoint 2\n");

    i = 0;
    ans = 0;
    int denominator = 1;
    while(occurence_arr[i]!=0 && i!=len-1)
    {
        denominator = denominator * fact(occurence_arr[i])  ;
        i++;
    }

    // printf("checkpoint 3\n");

    i=0;
    j=0;
    int first_letter = rank_arr[0] ;
   while( sorted_arr[i] != first_letter )      // calculating cases with initial letter < given initial letter('P' in this case)
   {
       x = occurence_arr[j];
       int d = pow(denominator,(1000003-2));//x is the occurrence number of the letter-> sorted_array[i]

       ans =ans + (fact(len-1)*x %1000003) * d%1000003;    //adjusting the repetition of cases of the first letter combinations
       i= i + x ;
       j++ ;
   }
  //  printf("rank function gives : %d\n ", ans );

     return ans = ans + findRank(A+1) ;
      //return ans%1000003;
 }
 void main()
{
    int a;
    a = findRank("asdasdasdasdasdasd");
     printf("rank: %d", a+1);

}
 // sadasdsasassasas
 // ans = 208526
