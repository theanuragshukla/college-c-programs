#include <stdio.h>

void printArray(int arr[], int n ){
	for(int i = 0; i< n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int arr[], int n){
	for(int i = 0; i< n;i++){
		for(int j = 0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printArray(arr, n);
}

void selectionSort(int arr[], int n){
	for(int i = 0; i< n; i++){
		int min = i;
		for(int j = i; j<n; j++){
			if(arr[j]<arr[min])min=j;
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	printArray(arr, n);
}


void insertionSort(int arr[], int n){
	for(int i = 1; i< n; i++){
		int temp = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	printArray(arr, n);
}

void merge(int* arr, int l, int m,  int h){
	int n1 = m-l;
	int n2 = h- m;
	int arr1[n1], arr2[n2], i= l, j=m;
	for(int i = l; i<m; i++)arr1[i] = arr[i];
	for(int i =m  ; i<h; i++)arr2[i] = arr[i];
	int k = 0; i = 0; j = 0; 
	while(i<n1 && j<n2){
		if(arr1[i]<arr2[j]){
			arr[l+k++] = arr1[i++];
		}else{
			arr[l+k++] = arr2[j++];
		}
	}
	while(i<n1){
		arr[l+k++] = arr1[i++];
	}
	while(j<n2){
		arr[l+k++] = arr[j++];
	}

}

void mergeSort(int arr[], int l, int h ){
	if(l<h){
		int m = (l+h)/2;
		mergeSort(arr, 0, m);
		mergeSort(arr, m, h);
		merge(arr, l, m, h);
	}
}


int main (){
	int arr[] = {5, 6 , 1, 3, 2, 4};
	bubbleSort(arr, 6);
	selectionSort(arr, 6);
	insertionSort(arr, 6);
	mergeSort(arr, 0, 6);
	return 0;
}
