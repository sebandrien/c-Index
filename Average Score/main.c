#include <stdio.h>

int main ()

{
   float score_1, score_2, score_3, score_4, score_5;
   float sum, average;
    
   printf ("Enter the scores for 5 subjects separated by a space: "); 
   scanf ("%f %f %f %f %f", &score_1, &score_2, &score_3, &score_4, &score_5);
   
   sum = score_1 + score_2 + score_3 + score_4 + score_5;
   average = sum / 5;
   
    
   printf ("Total score: %f\n", sum);
   printf ("Percentage: %.6f %%", average);

   return 0;
}
