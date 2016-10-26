#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//Definition for an interval.
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
struct Interval* insert(interval *intervals, int sz, interval newInterval, int *len)
{
        int i, j, k, z;
        int ns = newInterval.start;
        int ne = newInterval.end;
        // cases: overlapping intervals & non-overlapping intervals
        for(i=0; i<sz-1; i++)
        {
             if(ns>=intervals[i].end && ns<=intervals[i+1].start && ne<=intervals[i+1].start)
                {
                     //case 5.. one new interval
                      struct Interval* new_array = (struct Interval*)malloc((sz+1)*sizeof(struct Interval));
                    *len = sz + 1;
                      for(j=0; j<(i+1); j++)
                      {
                          new_array[j].start = intervals[j].start;
                          new_array[j].end = intervals[j].end;
                       }
                       new_array[j].start = ns;
                       new_array[j].end = ne;
                       j++;
                       i++;
                       for(k = j; k < (sz+1); k++)
                       {
                            new_array[k].start = intervals[i].start;
                            new_array[k].end = intervals[i].end;
                            i++;
                       }

                      return new_array;
                }

                  else  if(ns>=intervals[i].start && ns<=intervals[i].end)
                     {
                            if(ne>=intervals[i].end)
                            {
                                if(ne<=intervals[i+1].start)
                                {
                                    //case1.  no new interval
                                    *len = sz;
                                    intervals[i].end = ne;
                                    return intervals;
                                }
                                else
                                {
                                    for(j=i+2; i+j<sz; j++)
                                    {
                                        if(ne<=intervals[j].start)
                                        {

                                        }
                                    }
                                }
                            }
                            else if(ne>=intervals[i].end )

                     }
                     else if(ns>=intervals[i].end && ns<=intervals[i+1].start)
                     {

                     }

        }
}

void main()
{
            int sz, i, j;
            printf("Number of intervals?\n");
            scanf("%d", &sz);
            struct Interval* intervals = (struct Interval*)malloc(sz*sizeof(struct Interval));
            int* len = (int*)malloc(sizeof(int));
            *len = sz;
            printf("\nEnter the intervals:");
            for(i=0; i<sz; i++)
            {
                int s, e;
                scanf("%d %d", &s, &e);
                intervals[i].start = s;
                intervals[i].end = e;
                //printf("\n%d %d", intervals[i].start, intervals[i].end);
            }
            printf("\nEnter interval to be inserted: ");
            struct Interval* newInterval = (struct Interval*)malloc(sizeof(struct Interval));
            scanf("%d %d", &newInterval->start, &newInterval->end);
            printf("%d %d", newInterval->start, newInterval->end);

            struct Interval* result = insert(intervals, sz, *newInterval, len);
            int new_length = *len;
            printf("\nNew intervals: ");
            for(i=0; i<new_length; i++)
            {
                printf("(%d,%d) ", result[i].start, result[i].end);
            }
}


