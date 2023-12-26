#include<stdio.h>
struct example
{
	int a;
	float b;
	char c;
}var;
union data
{
	int x;
	float y;
	char z;
}uni;
int main()
{
	struct example var1;    
	union data uni;  
	
	var.a=1; 
	var.b=1.2;
	var.c='A';

	var1.a=12;  
	var1.b=1.5;
	var1.c='C';

	printf("\n%d\n%f\n%c",var.a,var.b,var.c);

	printf("\n%d\n%f\n%c",var1.a,var1.b,var1.c);

	uni.y=15.5;
	uni.z='U';
	uni.x=122;
	
	printf("\n%d\n%f\n%c",uni.x,uni.y,uni.z);
	return 0;
}
