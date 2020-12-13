/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>

using namespace std;


int main() {

    int n, adj[101], deg[101], x, y;
    queue<int> q;
    register int i, k = 1;
    
    while (scanf("%d", &n) && n) {
        for (i = 1; i <= n; i++) deg[i] = adj[i] = 0;
        for (i = 1; i < n; i++) {
            scanf("%d %d", &x, &y); adj[x] += y; adj[y] += x; deg[x]++; deg[y]++;
        }
        if (n == 1) { printf("Teste %d\n1\n\n", k++); continue; }
        while (!q.empty()) q.pop();
        for (i = 1; i <= n; i++) if (deg[i] == 1) q.push(i);
        while (!q.empty()) {
            x = q.front(); q.pop(); deg[adj[x]]--; adj[adj[x]] -= x;
            if (deg[adj[x]] == 1) q.push(adj[x]); deg[x] = 0;
        }
        printf("Teste %d\n%d\n\n", k++, x);
    }
    
    return 0;
}

