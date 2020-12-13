/* Série de Tubos */

#include <stdio.h>

int n, m;
char g[1001][1001];
char used[1001][1001];
int tree[1000][2];
int nt;
char disc[1001];
int par[1001];
char fim;

void MST(int v) {
    
    int i;
    
    disc[v] = 1;
    
    for (i = 1; i <= n; i++)
        if ((g[v][i]) && (!disc[i])) {
            tree[nt][0] = v; tree[nt][1] = i;
            nt++;    
            MST(i);
        }
}    

void DFS(int v, int t) {
    
    int i;
    
    disc[v] = 1;
    if (v == t) { fim = 1; return; }
    
    for (i = 1; i <= n; i++)
        if ((g[v][i]) && (!disc[i])) {
            par[i] = v;
            DFS(i, t);
            if (fim) return;
        }
}


int main() {
    
    int i, j;
    int a, b;
    
    while (scanf("%d %d", &n, &m)) {
     
        if ((!n) && (!m)) break;
        
        for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) g[i][j] = 0;
        
        for (i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            g[a][b] = g[b][a] = 1;
            used[a][b] = used[b][a] = 0;
        }
        
        /* Caso haja uma ponte, ela deve estar em uma arvore minima gerada */
        nt = 0;
        for (j = 1; j <= n; j++) disc[j] = 0;
        MST(1);
        
        /* Para cada ramo da arvore, verificar se eh ponte */
        for (i = 0; i < nt; i++)
            if (!used[tree[i][0]][tree[i][1]]) {
                g[tree[i][0]][tree[i][1]] = g[tree[i][1]][tree[i][0]] = 0;
                
                for (j = 1; j <= n; j++) { disc[j] = 0; par[j] = -1; }
                fim = 0;
                DFS(tree[i][0], tree[i][1]);
                
                if (!fim) break;
                else {
                    a = tree[i][1];
                    while (a != tree[i][0]) {
                        used[par[a]][a] = used[a][par[a]] = 1;
                        a = par[a];
                    }
                }
                used[tree[i][0]][tree[i][1]] = used[tree[i][1]][tree[i][0]] = 1;
                
                g[tree[i][0]][tree[i][1]] = g[tree[i][1]][tree[i][0]] = 1;
            }        
        
        if (i != nt) printf("N\n");
        else printf("S\n");
    }
    
    return 0;
}
