#include<stdio.h>
void display(int);
int main(){
	int a[5]={1,2,3,4,5};
	int i;
	for(i=0;i<5;i++){
		display(&a[i]);
	}
	return 0;
}
void display(int *num){
	printf("\n%d",*num);
}
