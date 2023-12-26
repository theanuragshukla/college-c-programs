#include <stdio.h>

int main(void) {
  int size;
  int i;

  printf("Enter the size of the binary code: ");
  scanf("%d", &size);

  int binary[size];
  int gray[size];

  printf("Enter the binary code: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &binary[i]);
  }

  gray[0] = binary[0];
  for (i = 1; i < size; i++) {
    gray[i] = binary[i] ^ binary[i - 1];
  }

  printf("Gray code: ");
  for (i = 0; i < size; i++) {
    printf("%d", gray[i]);
  }
  printf("\n");

  return 0;
}
