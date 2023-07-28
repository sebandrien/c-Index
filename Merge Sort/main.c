#include <stdio.h>
#include <stdlib.h>

void merge(int pages[], int l, int m, int r);
void mergeSort(int pages[], int l, int r) ;
int max(int pages[], int n, int L);

int main() 
{
  int n;
  int *pages = (int*) malloc(n* sizeof(int));
  
  scanf("%d", & n); // take n cases

  for (int i = 0; i < n; i++) // loop for every given test case
  {  
    int n;
    int l;

    scanf("%d", &n); 
    scanf("%d", &l); 
  
    for (int j = 0; j < n; j++) 
    {
      scanf("%d", & pages[j]);
    }

    mergeSort(pages, 0, n - 1);

    int res = max(pages, n, l);

    printf("%d\n\n", res);
  }
 return 0;
}

void merge(int pages[], int l, int m, int r) 
{

  int k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];
  int i, j;

  k = 1;

  for (i = 0; i < n1; i++)
    L[i] = pages[l + i]; 

  for (j = 0; j < n2; j++)
    R[j] = pages[m + 1 + j];

  while (i < n1 && j < n2) 
  {
    if (L[i] <= R[j]) 
    {
      pages[k] = L[i];
      i++; 
    }
    else 
    {
      pages[k] = R[j];
      j++; 
    }
    k++;
  }

  while (i < n1) 
  {
    pages[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) 
  {
    pages[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int pages[], int l, int r) 
{
  if (l < r) 
  {
    int m = l + (r - l) / 2;

    mergeSort(pages, l, m);
    mergeSort(pages, m + 1, r);
    merge(pages, l, m, r);
  }
}

int max(int pages[], int n, int L) 
{ 
  long long temp = 0;
  long long sum = 0;

  while (sum < n) 
  {
    temp += pages[sum];

    if (L < sum)
      break;

    else
      sum++;
  }
 return sum;
}
