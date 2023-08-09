#include <stdio.h>

int main () 
{
  int num,d1,d2,d3,d4,d5,sum;
    
  printf("Enter a five digit number : "); 
  scanf("%d", &num);
    
  d1 = num % 10;
  num = num / 10;
    
  d2 = num % 10;
  num = num / 10;
    
  d3 = num % 10;
  num = num / 10;
    
  d4 = num % 10;
  num = num / 10;
    
  d5 = num;
  num = d1 * 10000 + d2 *1000 + d3 *100 +d4 *10 + d5;

  printf("Reverse Number: %d\n", num);
    
  sum =  d1 + d2 + d3 + d4 + d5;
    
  printf("\nSum of digits: %d + %d + %d + %d + %d = %d\n", d5, d4, d3, d2, d1, sum);
    
 return 0;
}
