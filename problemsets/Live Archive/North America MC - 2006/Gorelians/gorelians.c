/* Go Go Gorelians */

#include <stdio.h>

typedef struct {
    int x, y, z;
    int id;
} planet;

char g[1050][1050];
int degree[1050];


int n;
planet p[1050];

double dist(planet *a, planet *b) {

    return ((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y)+
            (a->z-b->z)*(a->z-b->z));    
}

int parent(int k) {

    int i;
    int min, d;
    int par;
    
    min = 2000000000;
    for (i = 0; i < k; i++)
        if ((d = dist(&p[i], &p[k])) < min) {
            min = d;
            par = i;
        }
    return (par);
}

void greedy() {

    int leaf[1050], nl;
    char v[1050];
    int c;
    int r[2], nr;
    int i, j;
    
    for (i = 0; i < n; i++) v[i] = 1;
    c = 0;
    while (1) {
        nl = 0;
        for (i = 0; i < n; i++)
            if (degree[i] == 1) 
                leaf[nl++] = i;
        
        for (i = 0; i < nl; i++) {
            c++;
            v[leaf[i]] = 0;
            degree[leaf[i]] = 0;
            for (j = 0; j < n; j++)
                if ((j != leaf[i]) && (g[j][leaf[i]])) {
                    g[j][leaf[i]] = g[leaf[i]][j] = 0;
                    degree[j]--;
                }
        }
        
        if (c >= n-2) break;
    }
    
    nr = 0;
    for (i = 0; i < n; i++)
        if (v[i])
            r[nr++] = p[i].id;
    
    if (nr == 2) {
        if (r[0] < r[1]) printf("%d %d\n", r[0], r[1]);
        else printf("%d %d\n", r[1], r[0]);
    }
    else printf("%d\n", r[0]);
}


int main() {

    int i, j;
    int par;
    
    while (scanf("%d", &n)) {
        
        if (!n) break;
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                g[i][j] = g[j][i] = 0;
            degree[i] = 0;
        }
        
        for (i = 0; i < n; i++) {
            scanf("%d %d %d %d", &p[i].id, &p[i].x, &p[i].y, &p[i].z);
            if (i != 0) {
                par = parent(i);
                g[i][par] = g[par][i] = 1;
                degree[i]++;
                degree[par]++;
            }
        }
        
        greedy();
    }
    
    return 0;    
}
