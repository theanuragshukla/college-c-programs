#include <stdio.h>
int main(){
	int num = 0;
	printf("enter a year: ");
	scanf("%d",&num);
	printf ("the year %d is ",num)
	num%4==0 ? printf("leap year") : printf("not a leap year");
	return 0;
}
