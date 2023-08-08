#include <stdio.h>

int main(void) {
    
  int a, b, temp, ret;
  
  printf("Enter two integers:\n");
  
  while ((ret = scanf("%d %d", &a, &b)) != 2) 
  {
      printf("Invalid input. Please enter two integers.\n");
      while(getchar() != '\n'); 
  }
  
  printf("Before swapping, a is %d and b is %d", a, b);

  temp = a;
  a = b;
  b = temp;

  printf("\nAfter Swapping, a is %d and b is %d\n", a, b);
  
 return 0;
}
