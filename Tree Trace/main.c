#include <stdio.h>
#include <math.h>
#define resdistance 0
#define treemax 500

void distance() {

  int n;
  int tree[0][0];
  int tree2[0][0];
  float distance;
  float result = 0;

  for (int i = 1; i <= 2 * n; i++) 
  {
    int distance = tree[i][0] - tree2[i][0] + tree[i][0] - tree2[i][0];
  }

  result = sqrt(distance);
}

int calculate() {
    
  int n = 0;
  int tree[13][2];

  for (int i = 1; i <= 2 * n; i++) {
    if (tree[i][0])
      break;
  }

  for (int i = 1; i <= 2 * n; i++) {
    if (tree[i][0]) {
      calculate();

    }
  }
}

int main() {

  int n;
  int t;
  float minimumDistance = 0;

  int point[0][0];

  scanf("%d", & n);

  while (n--) {

    scanf("%d", & t);

    int trees = n * 2;

    for (int i = 1; i <= trees; i++) {
      scanf("%d %d", & point[i][0], & point[i][0]);
    }

    if (point[0][0] == 0)
      return 0;
      
    calculate();

    printf("%0.3lf", minimumDistance);
  }
}
