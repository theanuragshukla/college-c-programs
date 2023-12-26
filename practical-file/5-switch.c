#include<stdio.h>
int main(){
	int age,res;
	printf("Enter you age: ");
	scanf("%d",&age);
	res = age>=18;
		switch(res){
			case 1:
				res=1;
				break;
			case 0:
				res=0;
				break;
			default:
				return 0;
		}
	printf("\nYou are %seligible to vote",res?"":"not ");
	return 0;
}
