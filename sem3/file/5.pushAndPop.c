#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

void push(int value) {
  if (top != MAX_SIZE - 1) stack[++top] = value;
}

void pop() {
  if (top != -1) top--;
}
int main() {
  int choice, value;

  while (1) {
	printf("1. Push\n2. Pop\n3. Exit\nEnter your choice: ");
	scanf("%d", &choice);

	choice == 1 ? (printf("Enter the value to push: "), scanf("%d", &value), push(value)) :
	choice == 2 ? pop() :
	choice == 3 ? exit(0) : printf("Error: invalid choice\n");
  }
}
