/* How Big Is It */

#include <stdio.h>
#include <math.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXPERM 8

double d[MAXPERM+3][MAXPERM+3];
double distance[MAXPERM+3][MAXPERM+3];
double radius[MAXPERM+1];
double size;

void process_solution(int a[], int m) {
    
    int i, j, k;
    
    for (i = 0; i <= MAXPERM+1; i++)
        for (j = 0; j <= MAXPERM+1; j++)
            d[i][j] = -100.0;

    for (j = 1; j <= m+1; j++)
        for (i = 0; i <= m-j+1; i++) {
            if ((i == 0) && (j <= m))
                d[0][j] = radius[a[j]];
            else if ((i+j == m+1) && (i > 0))
                d[i][m+1] = radius[a[i]];
            else if ((i > 0) && (i+j <= m))
                d[i][i+j] = distance[a[i]][a[i+j]];
            
            for (k = i+1; k < i+j; k++)
                if (d[i][i+j] < d[i][k]+d[k][i+j])
                    d[i][i+j] = d[i][k]+d[k][i+j];
        }

    if (d[0][m+1] < size)
        size = d[0][m+1];
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {

    int i, j;
    bool inperm[MAXPERM+1];
    
    for (i = 1; i <= n; i++) inperm[i] = FALSE;
    for (i = 1; i < k; i++) inperm[a[i]] = TRUE;
    
    *ncandidates = 0;
    for (i = 1; i <= n; i++)
        if (inperm[i] == FALSE) {
            for (j = 0; j < *ncandidates; j++)
                if (radius[i] == radius[c[j]])
                    break;
            if (j == *ncandidates) {
                c[*ncandidates] = i;
                (*ncandidates)++;
            }
        }
}

void backtrack(int a[], int k, int n) {
    
    int c[MAXPERM+1];
    int ncandidates;
    int i;
    
    if (k == n)
        process_solution(a, k);
    else {
        k++;
        construct_candidates(a, k, n, c, &ncandidates);
        for (i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            backtrack(a, k, n);
        }  
    }
}


int main() {
    
    int cases;
    int m;
    int i, j;
    int sol[MAXPERM+1];
    double a, b;
    
    scanf("%d", &cases);
    while (cases) {
        
        scanf("%d", &m);
        for (i = 1; i <= m; i++)
            scanf("%lf", &radius[i]);
        
        for (i = 1; i <= m; i++)
            for (j = i+1; j <= m; j++) {
                a = radius[i] + radius[j];
                b = fabs(radius[i] - radius[j]);
                distance[i][j] = distance[j][i] = sqrt((a*a) - (b*b));
            }
        
        size = 10e10;
        backtrack(sol, 0, m);
        printf("%.3lf\n", size);
        
        cases--;
    }    
    
    return 0;
}
