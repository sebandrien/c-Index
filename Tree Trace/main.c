#include <stdio.h>
#include <math.h>

#define TREEMAX 500

void calculateDistance(int tree[][2], int tree2[][2], int n, float *result) 
{
    for (int i = 0; i < n; i++) 
    {
        float distance = sqrt(pow((tree[i][0] - tree2[i][0]), 2) + pow((tree[i][1] - tree2[i][1]), 2));
        if(distance > *result)
            *result = distance;
    }
}

void calculate(int tree[][2], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        if (tree[i][0] == 0)
            break;
    }
}

int main() 
{
    int n, t;
    int point[TREEMAX][2];
    float minimumDistance = 0.0;
    
    scanf("%d", &n);
    
    while (n--) 
    {
        scanf("%d", &t);
        
        for (int i = 0; i < t; i++) 
        {
            scanf("%d %d", &point[i][0], &point[i][1]);
        }
        
        calculate(point, t);

        // Assuming you want to calculate distance between the two sets of points. 
        // Since it's not clear from the initial code, the below line is just a placeholder.
        calculateDistance(point, point, t, &minimumDistance);
        
        printf("%.3f\n", minimumDistance);
    }
    
    return 0;
}
