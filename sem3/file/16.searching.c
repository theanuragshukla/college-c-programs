#include<stdio.h>
void swap(int *a ,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubbleSort(int * ar,int l){
	int i=0, j=0;
	for(i=0;i<l-1;i++)
		for(j=0;j<l-i-1;j++) 
			if(*(ar+j)>*(ar+j+1)) swap((ar+j),(ar+j+1));
	for(i=0;i<l;i++) printf("%d ",*(ar+i));
	printf("\n");
}
void insertionSort(int arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;}
		arr[j + 1] = key;
	}
	for(i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}
void selectionSort(int arr[], int n){
	int i, j, min;
	for (i = 0; i < n-1; i++){
		min = i;
		for (j = i+1; j < n; j++)
			if (arr[j] < arr[min]) min = j;
		if(min!=i) swap(&arr[min], &arr[i]);
	}
	for ( i = 0; i < n; i++) printf("%d ",arr[i]);
	printf("\n");
}
int partioning(int arr[],int l ,int h){
	int pivot = arr[l];
	int i=l, j=h;
	while(i<j){
		while(arr[i]<=pivot)i++;
		while (arr[j]>pivot) j--;
		if(i<j)
			swap(&arr[i],&arr[j]);
	}
	swap(&arr[j],&arr[l]);
	return j;
}
void quickSort(int arr[],int l , int h){
	if(l<h){
		int part=partioning(arr,l,h);
		quickSort(arr,l,part-1);
		quickSort(arr,part+1,h);
	}}
void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; j = 0; k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++; k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++; k++;
	}
}
void mergeSort(int arr[],int l,int h){
	if(l<h){
		int mid = l+(h-l)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,h);
		merge(arr,l,mid,h);}
}
int main(){
	int i=0;
	int n;
	printf("Enter size: ");
	scanf("%d",&n);
	int ar[n];
	printf("Enter Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	bubbleSort(ar,n);
	insertionSort(ar,n);
	selectionSort(ar,n);
	quickSort(ar,0,n);
	mergeSort(ar,0,n);
}
