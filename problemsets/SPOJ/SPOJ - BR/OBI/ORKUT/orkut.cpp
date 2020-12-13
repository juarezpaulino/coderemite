/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>
#include <map>
#include <string>
#include <string.h>

using namespace std;


map<string, int> mapa;
char nome[30][20];
int deg[30], adj[30][30], nadj[30], out[30];
queue<int> q;


int main() {
    
    int n, m;
    register int i, j, k = 1, x, y;
    char str[20];
    while (scanf("%d ", &n) && n) {
        for (i = 0; i < n; i++) { scanf("%s ", str); mapa[str] = i; strcpy(nome[i], str); nadj[i] = 0; }
        for (i = 0; i < n; i++) {
            scanf("%s %d", str, &m); x = mapa[str]; deg[x] = m;
            if (!deg[x]) q.push(x);
            while (m--) { scanf("%s ", str); y = mapa[str]; adj[y][nadj[y]++] = x; }
        }
        i = 0;
        while (!q.empty()) {
            x = q.front(); q.pop(); out[i++] = x;
            for (j = 0; j < nadj[x]; j++) {
                y = adj[x][j]; deg[y]--; if (!deg[y]) q.push(y);
            }
        }
        if (i < n) printf("Teste %d\nimpossivel\n\n", k++);
        else {
            printf("Teste %d\n", k++);
            for (i = 0; i < n-1; i++) printf("%s ", nome[out[i]]);
            printf("%s\n\n", nome[out[i]]);
        }
    }
    return 0;
}

