#include<stdio.h>
#include<stdlib.h>

int stepscount( int startx, int starty, int endx, int endy);
int coverPoints(int* X, int n1, int* Y, int n2) {
    int i,j;
    i = j = 0;

    int steps =0;

    for(i=0;i<n1-1;i++)
    {
        steps = steps + stepscount(  X[i], Y[i], X[i+1],Y[i+1]);
    }

    //printf("%d", steps);
    return steps;

}

int stepscount( int startx, int starty, int endx, int endy)
{
    int count = 0;
    while( startx!=endx || starty!= endy)
    {

         if(endx>startx && endy>starty)         // NE
        {
            startx++;
            starty++;
            count++;
             printf("NE\n");
            continue;
        }
         else if(endx>startx && endy<starty)         // SE
        {
            startx++;
            starty--;
            count++;
             printf("SE\n");
            continue;
        }
         else if(endx<startx && endy<starty)         // SW
        {
            startx--;
            starty--;
             printf("SW\n");
            count++;
            continue;
        }
         else if(endx<startx && endy>starty)         // NW
        {
            startx--;
            starty++;
            count++;
             printf("NW\n");
            continue;
        }
        else if(endx == startx && endy>starty)       //move up
        {
            starty++;
            count++;
            printf("up\n");
            continue;
        }
        else if(endx == startx && endy<starty)       //move down
        {
            starty--;
            count++;
             printf("down\n");
            continue;
        }
        else if(endy == starty && endx<startx)       //move left
        {
            startx--;
            count++;
             printf("left\n");
            continue;
        }
        else if(endx>startx)       //move right
        {
            startx++;
            count++;
             printf("right\n");
            continue;
        }
    }
    return count;
}

int steps_optimised(int startx, int starty, int endx, int endy)
{
    int X = abs(endx - startx);
    int Y = abs(endy - starty);
    if(X>Y){
        return X;
    }
    else return Y;
}


void main()
{
    int n,i;
    scanf("%d",&n);
    // printf("\n nn  ");
    int *x = (int*)malloc(n*sizeof(int));
    int *y = (int*)malloc(n*sizeof(int));

    printf("\nenter x: ");
    for(i=0; i<n; i++)
        {scanf("%d", &x[i]);}

    printf("\nEnter y: ");
    for(i=0; i<n; i++)
        {scanf("%d", &y[i]);}

    printf("\nsteps: %d",coverPoints(x, n, y, n));

}
