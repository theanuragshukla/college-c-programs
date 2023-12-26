#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int main ()
{
	char *str;
	/* Initial memory aLLocation*/
	str = (char *) malloc(25);
	strcpy(str, "Computers are useless.");
	printf("string = %s, Address = %u\n", str, &str);
	/* ReaLLocating memory */
	str = (char *) realloc(str,38);
	strcat(str, "They can only give you answers.");
	printf("String = %s, Address = %u\n", str, &str);
	/* DeaLLocate allocated memory */
	free(str);
	return(0);
}

