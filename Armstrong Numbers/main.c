#include <stdio.h>  

int sumDigitCube(int n) 
{      
    int sum, digit;
    sum = 0;
    
    while( n > 0 )
    {    
     digit = n % 10;
     n = n / 10; 
     sum = sum + digit * digit * digit;            
    }

    return sum;  
}  

int main() 
{  
  int n;
  
  printf("Enter a number: ");
  scanf("%d",&n);
  
  printf("The Armstrong numbers are: \n");
  for(int i=1;i<=n;i++)  
    {  
     if(sumDigitCube(i)==i)
       {
         printf("%d\n",i);
       }
    }
    return 0;  
} 
