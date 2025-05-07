#include <stdio.h>

int trianglePrinter(int n, int trianglesPrinted) {   
    int i, j;
 
    printf("Number of lines: %d\n", n);
     
    if (n > 0) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - i; j++) {
                printf("*");
            }
            printf("\n");
        }
        
        for (i = 2; i <= n; ++i) {  
            for (j = 1; j <= i; ++j) {
                printf("*");
            }
            printf("\n");      
        }   
        
        trianglesPrinted++; 
    }
    return trianglesPrinted;
}
    
int main() {
    int n;
    int totalTrianglesPrinted = 0;

    while (1) {   
        scanf("%d", &n);
        
        if (n < 0) {
            break;
        }
        
        totalTrianglesPrinted = trianglePrinter(n, totalTrianglesPrinted);  
    }
    
    printf("Total triangles printed: %d", totalTrianglesPrinted);
    
    return 0;
}
