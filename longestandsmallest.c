#include <stdio.h>
int main(){
	int a=0,b=0,c=0,smallest, largest;
	printf("enter three integer values: ");
	scanf("%d%d%d",&a,&b,&c);
	if (a>=b && a>=c){
		largest=a;
		smallest=b>c?c:b;
	}
	else if (b>=a && b>=c){
		largest=b;
		smallest=a>c?c:a;
	}
	else if (c>=b && c>=a){
		largest=c;
		smallest=b>a?a:b;
	}
	printf("\nthe smallest number is %d\nthe largest number id %d", smallest, largest);
	return 0;
}
