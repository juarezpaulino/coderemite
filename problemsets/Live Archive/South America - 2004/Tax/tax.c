/* Land Division Tax */

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int n;
double f;
int A[200][200];
double D[200][200];

int main() {
    
    int i, j, k, l;
    int ord;
    double min, d;
    
    while (scanf("%d %lf", &n, &f)) {
        
        if (!n) break;   
        
        for (i = 0; i < n; i++) scanf("%d", &A[i][i]);
        
        for (i = 0; i < n; i++) 
            for (j = i+1; j < n; j++) 
                A[i][j] = A[i][j-1]+A[j][j];
        A[n-1][0] = A[0][0]+A[n-1][n-1];
        for (i = n-2; i > 0; i--) A[i][0] = A[i+1][0] + A[i][i];
        for (i = n-1; i > 0; i--)
            for (j = 1; j < i; j++)
                A[i][j] = A[i][j-1] + A[j][j];
        
        for (i = 0; i < n; i++) D[i][i] = 0.0;
           
        for (ord = 1; ord < n; ord++) {
            for (i = 0; i < n-ord; i++) {
                j = i+ord;
                min = 1E14;
                for (k = i; k <= j-1; k++) {
                    d = max(A[i][k], A[k+1][j])*f + D[i][k] + D[k+1][j];
                    if (d < min) min = d;
                }
                D[i][j] = min;
            }
        }
        for (ord = 1; ord < n; ord++) {
            for (i = n-ord; i < n; i++) {
                j = i-n+ord;
                min = 1E14;
                for (k = i; (l = k%n) != j; k++) {
                    d = max(A[i][l], A[(l+1)%n][j])*f + D[i][l] + D[(l+1)%n][j];
                    if (d < min) min = d;
                }
                D[i][j] = min;
            }
        }
        
        min = D[0][n-1];
        for (i = 1; i < n; i++) if (D[i][i-1] < min) min = D[i][i-1];
        
        printf("%.2lf\n", min);
    }
    
    return (0);
}
