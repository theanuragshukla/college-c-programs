#include <stdio.h>
int main(){
	printf("enter a year: ");
	int   num = 0,idx = 1;
	scanf("%d",&num);
	printf("\n");
	do{
		printf("%d x %d = %d\n", num, idx, num*idx);
		idx++;
	}while(idx<11);
	return 0;
}
