#include<stdio.h>
#include<stdlib.h>

int main(){
	int n , *arr;
	printf("enter no. of elements: ");
	scanf("%d", &n);
	arr = (int*) calloc(n, sizeof(int));
	for(int i = 0; i<n;i++){
		scanf("%d", arr+i);
	}
	printf("\nElements you entered: ");
	for(int i = 0; i<n;i++){
		printf("%d ", arr[i]);
	}
}
