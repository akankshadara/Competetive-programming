#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//Definition for an interval.

//  [1,4] , [6,10] , [12,14] , [18,20]     ---- insert [15,17]
struct Interval
{
     int start;
     int end;
};

typedef struct Interval interval;
 /*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * newInterval : new Interval to be inserted
 * len : populate the length of returned array of intervals in len
 */

 interval* createNode(int x, int y )
 {
     interval* newN = (interval*)malloc(sizeof(interval));
     newN->start = x;
     newN->end = y;
     return newN;
 }

struct Interval* insert(interval *intervals, int sz, interval newInterval, int* len)
{
    int i, j, k , temp , temp2;
    int x , y;
    int length = sz;
    interval* ptr=NULL;
    interval* ptr2=NULL;
    x = newInterval.start;              //  [x , y]
    y = newInterval.end ;
    if(x>y)
    {
        int swap = x;
        x= y;
        y = swap;
    }

    interval* final_array;

    for(k=0;k<length;k++)
    {
        interval q = intervals[k];
        i = q.start;
        j = intervals[k].end;
       // printf("i:%d j:%d\n",i,j);
        if(x<=j)
        {
            //printf("value of K:%d \n", k);
            temp = k;
            temp2 = 0;
            //////////////////////case 1
            if(y<i)
            {
                interval* newnode = createNode(x,y);           // create a new node before current node
                final_array = (interval*)malloc((length+1)*sizeof(interval));

                while(temp2!=temp)                  // shifting the array into a new array.
                {
                    final_array[temp2] = intervals[temp2];
                    temp2++;
                }
                final_array[temp2++]= *newnode;
                while(temp!=length)
                {
                    final_array[temp2++]= intervals[temp++];
                }
                *len = *len+1;
                return final_array;
            }
            /////////////////////////
            else if( x>=i && y <=j)
            {
                   return intervals ;                       // [x,y] is in the interval [i,j]
            }
            else if(y>j)
            {
                while(temp2!=temp)                      //case to merge       // obviously y will be > i for this "if" case
                    temp2++;
                                                         // 1.) y intersects in next nodes OR 2.) y is b/w the vurrent & next node
                while(y>intervals[temp].end )
                {
                    temp++;
                }
                if(y<intervals[temp].start)
                {
                    final_array = (interval*)malloc(sizeof(interval)*(length-temp+temp2+1 ) );
                    int temp3 = 0;
                    while(temp3!=temp2)
                    {
                        final_array[temp3]=intervals[temp3];
                        temp3++;
                    }
                    final_array[temp2].end = y;
                    if(x>=i)
                        final_array[temp2++].start = i;
                    else
                        final_array[temp2++].start = x;
                    while(temp!=length)
                    {
                        final_array[temp2++] = intervals[temp++];
                    }
                    *len = temp2;
                    return final_array;
                }
                else if(y<intervals[temp].end)
                {
                    final_array = (interval*)malloc(sizeof(interval)*(length-temp+temp2 ) );
                    int temp3=0;
                    while(temp3!=temp2)
                    {
                        final_array[temp3]=intervals[temp3];
                        temp3++;
                    }
                    if(x>=i)
                        final_array[temp2].start = i;
                    else
                        final_array[temp2].start = x;
                    final_array[temp2++].end = intervals[temp++].end;
                    while(temp!=length)
                    {
                        final_array[temp2++] = intervals[temp++];
                    }
                    *len = temp2;
                    return final_array ;
                }
            }

            else if(x<i && y<=j)
            {
                intervals[k].start ;                       //y is b/w [i,j] and x < i .
                return intervals;
            }

        }
        else if(x>j)
        {
            interval* newnode = createNode(x,y);           // create a new node before current node
            final_array = (interval*)malloc((length+1)*sizeof(interval));
            temp2 = 0;
            while(temp2!=length)                  // shifting the array into a new array.
            {
                final_array[temp2] = intervals[temp2];
                temp2++;
            }
            final_array[length] = *newnode;
            *len = *len+1;
            return final_array;
        }
    }

}


void main()
{
    int i, j, size;
     int a,b;
    scanf("%d", &size);

    int* len = (int*)malloc(sizeof(int));
    *len = size;

    struct Interval* intervals = (interval*)malloc(size * sizeof(interval));
    for(i=0;i<size;i++)
    {
        scanf("%d %d",&a,&b);
        intervals[i].start = a;
        intervals[i].end = b;
    }

    interval* newInterval = (interval*)malloc(sizeof(interval));
    scanf("%d %d",&a,&b);
    newInterval->start = a;
    newInterval->end = b;

    //printf("%d %d\n", (newInterval->start) , newInterval->end);
    struct Interval* ans = (struct Interval*)malloc((*len)*sizeof(struct Interval));
    ans = insert(intervals , size , *newInterval , len);

    printf("ans \n and value of len returned %d\n",*len);
    for(i=0;i<(*len);i++)
    {
        printf("i %d--> ",i);
       printf("%d %d\n",ans[i].start , ans[i].end);
    }
    //return;
}
/*
4
100 600
800 1000
1200 1400
1800 2000

1500 1700
*/

/*
4
10 15
18 19
20 21
25 26
29 27
*/
