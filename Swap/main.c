#include <stdio.h>

int main(void) {
  int a, b, temp;

  scanf("%d%d", &a, &b);
  printf("Before swapping, a is %d and b is %d", a, b);

  temp = a;
  a = b;
  b = temp;

  printf("\nAfter Swapping, a is %d and b is %d\n", a, b);
  return 0;
}
