
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

typedef struct {
  int top;
  char items[MAX_EXPR_SIZE];
} Stack;

void push(Stack *stack, char x) {
  if (stack->top == MAX_EXPR_SIZE - 1) {
	fprintf(stderr, "Error: stack overflow\n");
	exit(1);
  }
  stack->items[++stack->top] = x;
}

char pop(Stack *stack) {
  if (stack->top == -1) {
	fprintf(stderr, "Error: stack underflow\n");
	exit(1);
  }
  return stack->items[stack->top--];
}

int is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c) {
  if (c == '+' || c == '-') {
	return 1;
  } else if (c == '*' || c == '/') {
	return 2;
  } else {
	return -1;
  }
}

void infix_to_postfix(const char *infix, char *postfix) {
  Stack stack = { .top = -1 };
  size_t i = 0, j = 0;
  while (infix[i] != '\0') {
	if (isdigit(infix[i])) {
  	postfix[j++] = infix[i];
	} else if (infix[i] == '(') {
  	push(&stack, infix[i]);
	} else if (is_operator(infix[i])) {
  	while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(infix[i])) {
    	postfix[j++] = pop(&stack);
  	}
  	push(&stack, infix[i]);
	} else if (infix[i] == ')') {
  	while (stack.items[stack.top] != '(') {
    	postfix[j++] = pop(&stack);
  	}
  	pop(&stack);
	} else {
  	fprintf(stderr, "Error: invalid character in expression\n");
  	exit(1);
	}
	i++;
  }
  while (stack.top != -1) {
	postfix[j++] = pop(&stack);
  }
  postfix[j] = '\0';
}

int main() {
  char infix[MAX_EXPR_SIZE], postfix[MAX_EXPR_SIZE];
  printf("Enter an infix expression: ");
  scanf("%s", infix);
  infix_to_postfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);
  return 0;
}
