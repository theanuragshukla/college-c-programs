#include<stdio.h>
int main(){
	int i=0,j=1;
	printf("printing using while loop:\n\n");
	while(i++<50) i%2 && printf("%d\n",i);
	printf("\nprinting using do-while loop:\n\n");
	do {
		j%2 && printf("%d\n",j); 
	}while(j++<50);	
	return 0;}
