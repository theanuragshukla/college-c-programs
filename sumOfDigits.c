#include <stdio.h>
int main(){
	printf("enter a number: ");
	int   num = 0,sum=0;
	scanf("%d",&num);
	while(num>0){
		if(num < 10){
			sum += num;
			break;
		}
		sum+=num%10;
		num/=10;
	}
	printf("the sum of digits of %d is %d",num,sum);
	return 0;
}
