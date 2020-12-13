/* Weights and Measures */

#include <stdio.h>
#include <stdlib.h>

#define MAXTURTLE 5607
#define MAXWEIGHT 65534

typedef struct {
    unsigned short w;
    unsigned short s;
} turtle;

unsigned short mw[2][MAXTURTLE];


int min(int a, int b) {

    if (a < b)
        return (a);
    else
        return (b);
}

int compare(const void *x, const void *y) {
    
    turtle *a = (turtle *) x;
    turtle *b = (turtle *) y;
    
    if (a->s != b->s)
        return (a->s - b->s);
    return (a->w - b->w);
}

int count_tower(turtle t[MAXTURTLE], int nturtles) {

    int i, j, k, aux, start;
  
    for (i = 0; i < nturtles; i++)
        mw[0][i] = 0;
    
    k = 1;
    for (j = 1; j <= nturtles; j++) {
        if (j > 1) {
            mw[k][j-2] = MAXWEIGHT;
            start = j-1;
        }
        else {
            mw[k][0] = t[0].w;
            start = 1;
        }
        for (i = start; i < nturtles; i++) {
            aux = mw[k^1][i-1] + t[i].w;
            if (aux <= t[i].s)
                mw[k][i] = min(aux, mw[k][i-1]);
            else
                mw[k][i] = mw[k][i-1];
        }
        if (mw[k][i-1] >= MAXWEIGHT)
            break;
        k = k^1;
    }
/*    for (i = 0; i < nturtles; i++)
        mw[i][0] = 0;
    mw[0][1] = t[0].w;
    for (j = 2; j <= nturtles; j++)
        mw[0][j] = MAXWEIGHT;
    
    for (j = 1; j <= nturtles; j++) {
        for (i = 1; i < nturtles; i++) {
            aux = mw[i-1][j-1] + t[i].w;
            if (aux <= t[i].s)
                mw[i][j] = min(aux, mw[i-1][j]);
            else
                mw[i][j] = mw[i-1][j];
        }
        if (mw[i-1][j] >= MAXWEIGHT)
            break;
    }*/
    
    return (j-1);
}


int main() {
    
    int n;
    int w, s;
    int max;
    turtle t[MAXTURTLE];
    
    n = 0;
    while (scanf("%d %d", &w, &s) != EOF) {
          t[n].w = w;
          t[n].s = s;
          n++;  
    }
    
    qsort(t, n, sizeof(turtle), compare);
    
    max = count_tower(t, n);
    printf("%d\n", max);
    
    return (0);
}
