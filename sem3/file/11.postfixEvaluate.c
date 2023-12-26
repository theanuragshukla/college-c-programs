#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_SIZE 100
typedef struct {
  int top;
  double items[MAX_EXPR_SIZE];
} Stack;

void push(Stack *stack, double x) {
  if (stack->top == MAX_EXPR_SIZE - 1) {
	fprintf(stderr, "Error: stack overflow\n");
	exit(1);
  }
  stack->items[++stack->top] = x;
}

double pop(Stack *stack) {
  if (stack->top == -1) {
	fprintf(stderr, "Error: stack underflow\n");
	exit(1);
  }
  return stack->items[stack->top--];
}

double eval_postfix(const char *expr) {
  Stack stack = { .top = -1 };
  for (size_t i = 0; i < strlen(expr); i++) {
	if (isdigit(expr[i])) {
  	push(&stack, expr[i] - '0');
	} else {
  	double y = pop(&stack);
  	double x = pop(&stack);
  	switch (expr[i]) {
    	case '+':
      	push(&stack, x + y);
      	break;
    	case '-':
      	push(&stack, x - y);
      	break;
    	case '*':
      	push(&stack, x * y);
      	break;
    	case '/':
      	push(&stack, x / y);
      	break;
    	default:
      	fprintf(stderr, "Error: invalid operator\n");
      	exit(1);
  	}}}
  return pop(&stack);
}
int main() {
  char expr[MAX_EXPR_SIZE];
  printf("Enter a postfix expression: ");
  scanf("%s", expr);
  printf("Result: %.2f\n", eval_postfix(expr));
  return 0;
}
