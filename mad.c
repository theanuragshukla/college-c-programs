#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
char ch;
char s[10];
char sen[100];

scanf("%c", &ch);
scanf("%s", s);
scanf("%[^\n]", sen);
printf("%c \n", ch);
printf("%s", s);
printf("%s",sen);


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
