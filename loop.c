#include<stdio.h>
int main(){
	long i = 1000000000;
	int p ;
	for(p=0;p<9999;p++){
		printf("%ld",i--);
	}
	return 0;
}
