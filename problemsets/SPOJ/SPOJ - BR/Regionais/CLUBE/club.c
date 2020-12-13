#include <stdio.h>
#include <stdlib.h>

#define MAXK 100000
#define MAXX 10001
#define INF 0x7FFFFFFF

int n, m;
int max;
int nl, ml;
int k;
int A[MAXK], B[MAXK], C[MAXX];
int l;

void counting_sort() {
    
    int i;
    
    for (i = 0; i <= max; i++) C[i] = 0;
    for (i = 0; i < k; i++) C[A[i]]++;
    for (i = 1; i <= max; i++) C[i] += C[i-1];
    for (i = k-1; i >= 0; i--) B[--C[A[i]]] = A[i];
}


int main() {
    
    int i, j, c;
    int nth, ntv;
    int x;
    
    while (scanf("%d %d", &n, &m)) {
        
        if (!n && !m) break;
        
        scanf("%d", &l);
        scanf("%d", &k);
        max = 0;
        for (i = 0; i < k; i++) { scanf("%d", &A[i]); if (A[i] > max) max = A[i]; }
        
        if (((n*100)%l) && ((m*100)%l)) { printf("impossivel\n"); continue; }
        
        counting_sort();
        
        /* Calcula tabuas na horizontal. */
        nth = INF;
        if (!((n*100)%l)) {
            nl = (n*100)/l;
            nth = 0;
            for (i = 0, j = k-1, c = 0; (i <= j) && (c < nl); ) {
                x = (i != j) ? (B[i]+B[j]) : INF;
                if (B[j] == m) { nth++; j--; c++; }
                else if (x == m) { nth+=2; i++; j--; c++; }
                else if (x > m) j--;
                else i++;
            }
            if (c < nl) nth = INF;
        }
        
        /* Calcula tabuas na vertical. */
        ntv = INF;
        if (!((m*100)%l)) {
            ml = (m*100)/l;
            ntv = 0;
            for (i = 0, j = k-1, c = 0; (i <= j) && (c < ml); ) {
                x = (i != j) ? (B[i]+B[j]) : INF;
                if (B[j] == n) { ntv++; j--; c++; }
                else if (x == n) { ntv+=2; i++; j--; c++; }
                else if (x > n) j--;
                else i++;
            }
            if (c < ml) ntv = INF;
        }
        
        if ((nth == INF) && (ntv == INF)) { printf("impossivel\n"); continue; }
        
        printf("%d\n", (nth < ntv) ? nth : ntv);
    }
    
    return 0;
}
