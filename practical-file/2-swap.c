#include<stdio.h>
int main(){
	int a,b,c;
	printf("enter two numbers: ");
	scanf("%d %d",&a,&b);
	printf("\nswapping a and b by using third variable c\n\n");
	c=a;a=b;b=c;
	printf("a = %d and b = %d\n\n",a,b);
	printf("swapping a and b again but without using variable c\n\n");
	a=a+b;b=a-b;a=a-b;
	printf("a = %d and b = %d\n\n",a,b);
	return 0;
}
