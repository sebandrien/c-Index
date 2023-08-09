#include <stdio.h>

int x = 0;

int updown_trianglePrinter(int n)
{   
  int i;
  int j;
 
  printf("Number of lines: %d\n", n);
     
  if (n >0) 
  {
    for(i = 0; i < n; i++) 
    {

        for(j = 0; j < n - i; j++) 
        {
            printf("*");
        }
       
        printf("\n");
    }
    
     for (i = 2; i <= n; ++i) 
     {
         
      for (j = 1; j <= i; ++j) 
      {
         printf("*");
         
      }
      printf("\n");      
   }   
   ++x;
    }   
 return 0;
}
    
int main()
{
  int n;

  while (1)
  {   
   scanf ("%d", &n);
   if (n < 0)
         {
             break;
         }
         updown_trianglePrinter(n);
        
    }
  printf("Total triangles printed : %d", x);
}
