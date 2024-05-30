#include <stdio.h>
#define SIZE 5

void display(int arr[], int size)
{ 
    for(int i=0; i<SIZE; i++)
    {
        printf("%d", arr[i]);
    }
}

int sumArray(int arr[], int size)
{
    int sum = 0;
        
    for(int i=0;i<SIZE;i++)
    {
        sum += arr[i];
    }
  
        return sum;
}

int findMax(int arr[], int n)
{
        int max;
        max = arr[0];
        
        for(int i=0; i<n; i++)
        {
          if(arr[i] > max) 
          
          max = arr[i];
        }
       
    return max;
}

int getDouble(int val)
{
        return 2 * val;
} 

int main()
{
    int arr[SIZE];
    int RevArray[SIZE];
    int max;
    
        for(int i=0;i<SIZE;i++)
        {
                printf("Enter number %d: ",(i+1));
                scanf("%d",&arr[i]);
        }
       
        display(arr, SIZE);
        max = findMax(arr, SIZE);
   
        printf("\nThe sum of myArray is: %d\n",sumArray(arr, SIZE));
        printf("The max value of myArray is: %d\n",max);
        printf("Double of %d is %d\n",arr[0], getDouble(arr[0]));
        printf("Double of %d is %d\n",arr[1], getDouble(arr[1]));
        printf("Double of %d is %d\n",arr[2], getDouble(arr[2]));
        printf("Double of %d is %d\n",arr[3], getDouble(arr[3]));
        printf("Double of %d is %d\n",arr[4], getDouble(arr[4]));
        
        for(int i=0; i<SIZE; i++)
        {
                RevArray[i] = arr[SIZE - (i+1)];
        }
        
        printf("Now the following data are from RevArray\n");
        display(RevArray, SIZE);
        printf("\nThe sum of revArray is: %d\n",sumArray(RevArray, SIZE));
        printf("The max value of revArray is: %d\n",findMax(RevArray, SIZE));
        printf("Double of %d is %d\n",RevArray[0], getDouble(RevArray[0]));
        printf("Double of %d is %d\n",RevArray[1], getDouble(RevArray[1]));
        printf("Double of %d is %d\n",RevArray[2], getDouble(RevArray[2]));
        printf("Double of %d is %d\n",RevArray[3], getDouble(RevArray[3]));
        printf("Double of %d is %d\n",RevArray[4], getDouble(RevArray[4]));
      
        return 0;
}
