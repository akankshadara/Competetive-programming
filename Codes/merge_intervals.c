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
  //(6037774, 6198243), (6726550, 7004541),
  // (8842554, 10866536), (11027721, 11341296), (11972532, 14746848), (16374805, 16706396),
  //(17557262, 20518214), (22139780, 22379559), (27212352, 28404611), (28921768, 29621583),
  // (29823256, 32060921), (33950165, 36418956), (37225039, 37785557), (40087908, 41184444),
  //(41922814, 45297414), (48142402, 48244133), (48622983, 50443163), (50898369, 55612831),
  // (57030757, 58120901), (59772759, 59943999), (61141939, 64859907), (65277782, 65296274),
  // (67497842, 68386607), (70414085, 73339545), (73896106, 75605861),
 //  (79672668, 84539434), (84821550, 86558001), (91116470, 92198054), (96147808, 98979097)

typedef struct Interval interval;
 /*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * newInterval : new Interval to be inserted
 * len : populate the length of returned array of intervals in len
 */
struct Interval* insert(interval *intervals, int sz, interval newInterval, int *len)
{
        int i, j, k;
        int ns = newInterval.start;
        int ne = newInterval.end;
        // cases: overlapping intervals & non-overlapping intervals
        for(i=0; i<sz-1; i++)
        {
            if(ns>=intervals[i].start && ne<=intervals[i].end)
            {
                //case 4.. no new interval
                *len = sz;
                return intervals;
            }

            else if(ns>=intervals[i].end && ns<=intervals[i+1].start)
            {
                if(ne>=intervals[i+1].end)
                {
                        //case 6.. no new interval
                        *len = sz;
                        intervals[i+1].start = ns;
                        intervals[i+1].end = ne;
                        return intervals;
                }
                else if(ne<=intervals[i+1].start)
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
                else if(ne<=intervals[i+1].end)
                {
                    //case 3.. no new interval
                    *len = sz;
                    intervals[i+1].start = ns;
                    return intervals;
                }
            }
            else if(ns>=intervals[i].start && ns<=intervals[i].end)
            {
                if(ne>=intervals[i].end && ne<=intervals[i+1].start)
                {
                    //case1.  no new interval
                    *len = sz;
                    intervals[i].end = ne;
                    return intervals;
                }
                else if(ne>=intervals[i+1].start && ne<=intervals[i+1].end )
                {
                    //case2.. Reduce one interval
                    struct Interval* result = (struct Interval*)malloc((sz-1)*sizeof(struct Interval));
                    *len = sz - 1;
                    for(j=0 ; j<i; j++)
                    {
                        result[j].start = intervals[j].start;
                        result[j].end = intervals[j].end;
                    }
                    j = i;
                    result[j].start = intervals[i].start;
                    result[j].end = intervals[i+1].end;
                    j++;
                    for(k=j; k<(sz-1); k++)
                    {
                        result[k].start = intervals[j].start;
                        result[k].end = intervals[j].end;
                        j++;
                    }
                    return result;
                }
            }
            else
            {
                return intervals;
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


