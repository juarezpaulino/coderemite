/* Long Night of Museums */

#include <stdio.h>
#include <stdlib.h>

#define MAXT 420
#define HEUR 5


int n;
int maxm;

int t[20];
int d[20][20];

int s[20];
int ns;
int best[20];
int nb;

char dom[20];
char finish;


int valid(int k) {
    
    int i;
    int time[20];
    
    if (!k) return (1);
    
    for (i = 0; i < k; i++) {
        if (i == 0) time[i] = t[s[i]];
        else time[i] = time[i-1] + d[s[i-1]][s[i]] + t[s[i]];
        
        if (time[i] > MAXT) return 0;
    }
    
    if ((k > nb) || ((k == nb) && (time[k-1] < best[k-1]))){
        nb = k;
        for (i = 0; i < k; i++ ) best[i] = time[i];
    } else
        for ( i = 0; i < k; i++ )
            if (time[i] > best[i] + HEUR) return 0;

    return 1;
}

void backtrack(int k) {
    
    int i;
    
    if (valid(k)) { 
        if (k == maxm) { finish = 1; return; }
        
        for (i = 0; i < n; i++) {
            if (!dom[i]) {
                dom[i] = 1;
                s[ns++] = i;
                
                backtrack(k+1);
                if (finish) return;
                
                ns--;
                dom[i] = 0;
            }
        }
    }
}


int main() {
    
    int i, j;
    int mind;
    int total;
    
    while (scanf("%d", &n)) {
        
        if (!n) break;
        
        maxm = n;
        total = 0;
        mind = 420;
        
        for (i = 0; i < n; i++) {
            scanf("%d", &t[i]);
            dom[i] = 0;
            total += t[i];
        }
        
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                scanf("%d", &d[i][j]);
                if ((i != j) && (d[i][j] < mind))
                    mind = d[i][j];
            }
        if (total+(mind*(n-1)) > MAXT) maxm -= 1;
        
        ns = nb = finish = 0;
        
        backtrack(0);
        
        printf("%d\n", nb);
    }
    
    return 0;
}    
