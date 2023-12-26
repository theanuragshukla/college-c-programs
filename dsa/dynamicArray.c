#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr = (int *) malloc(sizeof(int));
	int len = 0;
	for(int i = 0; i< 5; i++){
		arr = (int *) malloc(sizeof(int)*(len+1));
		scanf("%d\n", arr+len++);
	}
	for(int i = 0;i<len;i++){
		printf("%d ", *arr+i);
	}
	return 0;
}
