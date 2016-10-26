 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * @input A : Integer
 *
 * @Output string. Make sure the string ends with null character
 */
char* convertToTitle(int A, int *len1) {

	 int len = 0;
	  int rem, i=0, j;
	 char ch;
	 char *result = (char *)malloc(50 * sizeof(char));
	 while(A != 0)
	 {
        rem = A%26;
        A = A/26;
        if(rem == 0)
        {
            rem =26;
            A--;
        }
	     ch = 64 + rem;
	     result[i++] = ch;
	     printf("\na %d rem: %d char: %c  i:%d\n", A, rem, ch, i);
	     len++;
	 }

	 printf("len: %d\n", len);
	 *len1 = len;
	 char *result1 = (char *)malloc(len * sizeof(char));
	 for(i=0; i<len; i++)
	 {
	     result1[i] = result[len-i-1];
	 }
	 return result1;
}

void main()
{
    int i, num;
    char *result = (char *)malloc(100 * sizeof(char));
    scanf("%d", &num);

    int *len1 = (int*)malloc(sizeof(int));
    *len1 = 1;
    result = convertToTitle(num, len1);
    int len = *len1;
    printf("\nStrlen: %d\n", len);
    for(i=0; i<len; i++)
    {
            printf("%c",result[i]);
    }
}
