#include <stdio.h>

void copyString(int m,int n,char s1[]){
	char s2[100];
	int i;
	for ( i = 0;i<n;i++) {
		s2[i] = s1[i+m];
	}

	s2[i] = '\0';
	printf("String s2: %s", s2);
	
}

int main() {
	char s1[100];
	int n,m;
	printf("Enter string s1: ");
	fgets(s1, sizeof(s1), stdin);

	printf("Enter N: ");
	scanf("%d",&n);
	printf("Enter M: ");
	scanf("%d",&m);
	copyString(m,n,s1);
return 0;
}
