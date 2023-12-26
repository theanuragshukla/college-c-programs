#include <stdio.h>
int linear_search(int *arr, int n, int x) {
  for (int i = 0; i < n; i++) {
	if (arr[i] == x) {
  	return i;}}
  return -1;
}
int main() {
  int size, i, search;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &size);
  int array[size];
  printf("Enter %d integers: ", size);
  for (i = 0; i < size; i++) {
	scanf("%d", &array[i]);
  }
  printf("Enter the number to search for: ");
  scanf("%d", &search);
  int result = linear_search(array, size, search);
  if (result == -1) {
	printf("Element not found\n");
  } else {
	printf("Element found at index %d\n", result);
  }
  return 0;
}
