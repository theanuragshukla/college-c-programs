#include <stdio.h>
#include <math.h>
#include<stdlib.h>
long long toBinary(int n) {
	long long bin = 0;
	int rem, i = 1;
	while (n!=0) {
		rem = n % 2;
		n /= 2;
		bin += rem * i;
		i *= 10;
	}
	return bin;
}
int toDecimal(long long n) {
	int dec = 0, i = 0, rem;
	while (n!=0) {
		rem = n % 10;
		n /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	return dec;
}
int main() {
	int n, option=1;
	while(1){
		printf("\n1. Decimal to Binary\n2. Binary to Decimal\n3. exit\n");
		printf("choose the operation: ");
		scanf("%d",&option);
		if(option!=1 && option!=2)exit(0);	
		printf("\nEnter a %s number: ",option==1?"decimal":"binary");
		scanf("%d", &n);
		printf("\n%d => %lld\n", n, option==1?toBinary(n):toDecimal(n));}
	return 0;
}


