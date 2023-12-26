#include<stdio.h>

int main(void)
{
int i = 10;
if(i++==10){
	++i ? printf("1 ; i : %d , %d\n",i,i--) : printf("2 ; i : %d , %d\n",i,++i);
}else{
	while(1){
		printf("loop!");
	}
}
    return 0;
}
