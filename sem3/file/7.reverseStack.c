#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct stack {
    int data[MAX_SIZE];
    int top;
};
void init_stack(struct stack *ps);
int is_empty(struct stack *ps);
int is_full(struct stack *ps);
void push(struct stack *ps, int x);
int pop(struct stack *ps);
void reverse_stack(struct stack *ps);
void print_stack(struct stack *ps);

int main()
{
    struct stack s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    printf("Original stack: ");
    print_stack(&s);
    reverse_stack(&s);
    printf("Reversed stack: ");
    print_stack(&s);

    return 0;
}
void init_stack(struct stack *ps)
{
    ps->top = -1;
}
int is_empty(struct stack *ps)
{
    if (ps->top == -1)
        return 1;
    else
        return 0;
}
int is_full(struct stack *ps)
{
    if (ps->top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}
void push(struct stack *ps, int x)
{
    if (is_full(ps)) {
        printf("Error: stack is full\n");
        return;
    }

    ps->data[++(ps->top)] = x;
}
int pop(struct stack *ps)
{
    if (is_empty(ps)) {
        printf("Error: stack is empty\n");
        exit(1);
    }

    return ps->data[(ps->top)--];
}
void reverse_stack(struct stack *ps)
{
    int temp[MAX_SIZE];
    int i = 0;
    while (!is_empty(ps)) {
        temp[i++] = pop(ps);
    }
    for (int j = 0; j < i; j++) {
        push(ps, temp[j]);
    }
}
void print_stack(struct stack *ps)
{
    for (int i = ps->top; i >= 0; i--) {
        printf("%d ", ps->data[i]);
    }
    printf("\n");
}
