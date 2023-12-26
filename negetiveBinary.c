#include <stdio.h>

void print_binary(unsigned int number){
	if (number >> 1) {
		print_binary(number >> 1);
	}
	printf("%d", (number & 1) ?  1 : 0);
}

int main(){
	print_binary(-5);
	printf("\n");
	return 0;
}
