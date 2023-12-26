#include<stdio.h>

void insert(int arr[],int num){
	int newArr[arr.size()+1] ;
	bool done = false;
	for(int i =0;i<arr.size();i++){
		int prev = (i==0 ? -99999 : arr[i-1]);
		int next = (i==arr.length-1 ? 99999999 : arr[i+1]);
		if(next > num && prev <= num && !done){
			newArr[i]=num;
			done=true;
			i--;
		}else{
			if(done){
				newArr[i+1]=arr[i];
			}else{
				newArr[i]=arr[i];
			}
		}
	}

	for(int i =0;i<newArr.size();i++){
		printf("%d\n",newArr[i]);
	}
}


int main(){
	int arr[5]  = {1,2,4,5,6};
	insert(arr,3);
	return 0;
}

