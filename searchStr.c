#include<stdio.h>
#include<strings.h>

int searchStr(char str[] , char s2[]){
	if(s2==NULL){
		return 0;
	}
	int gotIt;
	int index = 0;
	while(str[index] != '\0'){
		if(str[index] == s2[0]){
			int i=0;
			gotIt = 1;
			while(s2[i] != '\0'){
				if(str[index + i] != s2[i]){
					gotIt = 0;
					break;
				}
				i++;
			}}
		if(gotIt == 1){
			break;
		}
		index++;
	}
	if(gotIt == 1){
		return index;
	}
	else{
		return 1;
	}
}

int main(){
	char s1[] = "helloworld";
	char s2[] = "low";
	int val =	searchStr(s1,s2);
	printf("%d",val);
	return 0;
}
