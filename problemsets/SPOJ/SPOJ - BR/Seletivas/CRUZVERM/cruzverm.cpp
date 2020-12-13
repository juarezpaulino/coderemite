/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>

using namespace std;

short adj[6001][6001], nadj[6001];
int deg[6001];
char in[6001], comp[6001];
int t, n, nb;
queue<int> q;


int main() {
    
    int i, x, y;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); for (i = 1; i <= n; i++) deg[i] = in[i] = comp[i] = nadj[i] = 0;
        for (i = 0; i < n-1; i++) {
            scanf("%d %d", &x, &y); deg[x]++; deg[y]++;
            adj[x][nadj[x]++] = y; adj[y][nadj[y]++] = x;
        }
        for (i = 1; i <= n; i++) if (deg[i]==1) q.push(i); nb = 0;
        while (!q.empty()) {
            x = q.front(); q.pop();
            if (comp[x]) continue;
            for (i = 0; i < nadj[x]; i++) {
                y = adj[x][i]; if (!in[x]) in[y] = 1; deg[y]--;
                if (deg[y]==1) q.push(y);
            }
            if (!in[x]) nb++; comp[x] = 1;
        }
        printf("%d\n", nb);
    }
    
    return 0;
}
