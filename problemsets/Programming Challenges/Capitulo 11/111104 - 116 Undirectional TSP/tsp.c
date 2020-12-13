/* Undirectional TSP */

#include <stdio.h>

#define MAXROW 10
#define MAXCOLUMN 100

int mw[MAXROW][MAXCOLUMN];


int min(int a, int b, int c) {
    
    if (a < b) {
        if (a < c)
            return (a);
        else
            return (c);
    }
    else {
        if (b < c)
            return (b);
        else
            return (c);
    }
}

int compare(const void *x, const void *y) {
    
    return(*(int *)x - *(int *)y);
}

void build_path(int mat[][MAXCOLUMN], int m, int n) {
    
    int i, j, k;
    int a[3];
    int w;
    int path[MAXCOLUMN];
    
    for (i = 0; i < m; i++)
        mw[i][n-1] = mat[i][n-1];
    
    for (j = n-2; j >= 0; j--) {
        for (i = 0; i < m; i++) {
            w = min(mw[(i+m-1)%m][j+1], mw[i][j+1], mw[(i+1)%m][j+1]);
            mw[i][j] = w + mat[i][j];
        }
    }
    
    w = mw[0][0];
    k = 0;
    for (i = 1; i < m; i++)
        if (mw[i][0] < w) {
            w = mw[i][0];
            k = i;
        }
    path[0] = k;
    for (j = 0; j < n-1; j++) {
        a[0] = (k+m-1)%m;
        a[1] = (k+m)%m;
        a[2] = (k+m+1)%m;
        qsort(a, 3, sizeof(int), compare);
        for (i = 0; i < 3; i++)
            if (mw[k][j] == mw[a[i]][j+1]+mat[k][j]) {
                k = a[i];
                break;
            }
        path[j+1] = k;
    }
    
    for (i = 0; i < n-1; i++)
        printf("%d ", path[i]+1);
    printf("%d\n",path[i]+1);
    printf("%d\n", w);
}


int main() {

    int m, n;
    int i, j;
    int mat[MAXROW][MAXCOLUMN];
    
    while (scanf("%d %d", &m, &n) != EOF) {
    
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
    
        build_path(mat, m, n);
    }    
    
    return (0);
}
