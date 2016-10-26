 /**
 * @input A : String termination by '\0'
 *
 * @Output Integer
 */
 #include<stdio.h>
#include<stdlib.h>
#include<math.h>

int titleToNumber(char* A)
{
    int i = 0, corres_num, column = 0, len=0;
    char ch;
    while(A[i] != '\0')
    {
        len ++;
        i++;
    }
     printf("%d\n", len);
    for(i=0; i<len; i++)
    {
        ch = A[i];
        corres_num = ch - 64;
        column = column + (corres_num * pow(26,len-1-i));
    }
    return column;
}

void main()
{
    char ch = 'A';
    int a = titleToNumber("ABC");
    printf("%d",a );
    //char ch1 = 67;
    //printf("%c", ch1);
}
