#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
  if (top == MAX_SIZE - 1) {
	printf("Error: stack overflow\n");
  } else {
	top++;
	stack[top] = value;
  }
}

void pop() {
  if (top == -1) {
	printf("Error: stack underflow\n");
  } else {
	top--;
  }
}

int peek() {
  if (top == -1) {
	printf("Error: stack is empty\n");
	return -1;
  } else {
	return stack[top];
  }
}

int main() {
  push(5);
  push(3);
  printf("%d\n", peek());
  pop();
  printf("%d\n", peek());
  pop();
  printf("%d\n", peek());
  return 0;
}
