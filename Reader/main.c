#include <stdio.h>
#include <math.h>

int main ()
{
    char n;
    int counter;
    
    printf("Enter a single character: "); 
    scanf("%c", &n);
    
     if(n >= 'A' && n <= 'Z')
     {
          counter = n - 64;
          printf("%c is a capital letter. The letter number is %d in the alphabet.", n, counter);
     }
    
     else if(n >= 'a' && n <= 'z')
     {
        counter = n - 96;
        printf("%c is a small case letter. The letter number is %d in the alphabet.", n, counter);
     }
        
     else if(n>= '0' && n <= '9')
     {
        printf("%c is a digit.", n); 
        
        int count = n - 48;
        double res = sqrt(count);
        
        printf("\nThe square root of %d is %.2lf", count, res);
     }
    
      else 
     {
        printf("%c is a special symbol.", n);
     }
      
  return 0;
}
