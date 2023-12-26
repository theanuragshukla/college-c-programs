#include<stdio.h>
int main(){
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,0,11};
	printf("%u %u",a+2,&a+3);
	return 0;
}
