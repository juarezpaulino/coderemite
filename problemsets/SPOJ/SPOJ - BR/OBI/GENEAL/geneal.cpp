/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <string>

using namespace std;

map<string, int> mapa;
short adj[1000][1000], nadj[1000];
char nome[1000][60];
int deg[1000];
int level[1000], filho[1000];
queue<int> q;
int n, nv;


int main() {
    
    register int i, j, k, f[2], s[2], nf;
    char x[60], y[60];
    
    scanf("%d ", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %s ", x, y);
        if (!mapa.count(x)) { j = mapa[x] = nv++; strcpy(nome[j], x); } else j = mapa[x];
        if (!mapa.count(y)) { k = mapa[y] = nv++; strcpy(nome[k], y); } else k = mapa[y];
        adj[k][nadj[k]++] = j; deg[j]++;
    }
    
    if (n == 1) { 
        if (strcmp(nome[0], nome[1]) < 0) printf("%s %s %d\n", nome[0], nome[1], 1);
        else printf("%s %s %d\n", nome[1], nome[0], 1);
        return 0;
    }
    
    for (i = 0; i < nv; i++) if (!deg[i]) { q.push(i); filho[i] = i; }
    
    nf = 0;
    while (!q.empty()) {
        j = q.front(); q.pop();
        for (i = 0; i < nadj[j]; i++) {
            k = adj[j][i];
            if (!nadj[k]) { if (deg[k] <= 2) {f[nf] = filho[j]; s[nf++] = level[j]+1;} deg[k]--; }
            else {
                if (level[j]+1 > level[k]) { level[k] = level[j]+1; filho[k] = filho[j]; }
                deg[k]--; if (deg[k]==0) q.push(k);
            }
        }
    }

    if (strcmp(nome[f[0]], nome[f[1]]) < 0) printf("%s %s %d\n", nome[f[0]], nome[f[1]], s[0]+s[1]);
    else printf("%s %s %d\n", nome[f[1]], nome[f[0]], s[0]+s[1]);
    
    return 0;
}

