#include <stdio.h>
#include <string.h>

void sortStr(char string[]){
	char temp;
	int i, j;
	int n = strlen(string);
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (string[i] > string[j]) {
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}

	printf("%s", string);

}

int main ()
{
	char string[100];
	scanf("%s",string);
	sortStr(string);
	return 0;
}

