#include<stdio.h>

int main(void)
{
	int x=0,y=-1,z=1;
	printf("%d",++x && ++y || ++z);
	printf("%d%d%d",x,y,z);
    return 0;
}
