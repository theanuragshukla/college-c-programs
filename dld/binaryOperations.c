#include <stdio.h>

#define SIZE 4

int main(void) {
  int a[SIZE] = {1, 0, 1, 0};
  int b[SIZE] = {0, 1, 1, 0};
  int c[SIZE];
  int i;
  char op;

  printf("Enter the operation to perform (AND, OR, NOT, XNOR, XOR, NAND): ");
  scanf("%c", &op);

  switch (op) {
    case 'A':
      for (i = 0; i < SIZE; i++) c[i] = a[i] & b[i];
      break;
    case 'O':
      for (i = 0; i < SIZE; i++) c[i] = a[i] | b[i];
      break;
    case 'N':
      for (i = 0; i < SIZE; i++) c[i] = !a[i];
      break;
    case 'X':
      for (i = 0; i < SIZE; i++) c[i] = op == 'N' ? !(a[i] ^ b[i]) : a[i] ^ b[i];
      break;
    case 'M':
      for (i = 0; i < SIZE; i++) c[i] = !(a[i] & b[i]);
      break;
    default:
      printf("Invalid operation.\n");
      return 1;
  }

  printf("Result: ");
  for (i = 0; i < SIZE; i++) printf("%d", c[i]);
  printf("\n");

  return 0;
}
