#include <stdio.h>
int main() {
  int size, i, search, first, last, middle;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &size);
  int array[size];
  printf("Enter %d integers: ", size);
  for (i = 0; i < size; i++) {
	scanf("%d", &array[i]);
  }
  printf("Enter the number to search for: ");
  scanf("%d", &search);
  first = 0;
  last = size - 1;
  middle = (first+last)/2;
 

 while (first <= last) {
	if (array[middle] < search) {
  	first = middle + 1;
	} else if (array[middle] == search) {
  	printf("%d found at location %d.\n", search, middle+1);
  	break;
	} else {
  	last = middle - 1;
	}
	middle = (first + last)/2;
  }
  if (first > last) 
	printf("%d is not present in the list.\n", search);
  return 0;
}
