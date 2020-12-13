/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int adj[1000][1000], nadj[1000], val[1000];
char disc[1000];
int n, p, k, comp;

void dfs(int v) {
    int i, f = 0;
    disc[v] = 1; comp++;
    for (i = 0; i < nadj[v]; i++) if (val[adj[v][i]]>=0 && !disc[adj[v][i]]) dfs(adj[v][i]);
}


int main() {
    
    int i, j, x, y, m, f;
    
    for (; n = get_int(), n; ) {
        p = get_int(), k = get_int();
        for (i = 0; i < n; i++) nadj[i] = disc[i] = 0;
        for (i = 0; i < p; i++) {
            x = get_int(), y = get_int();
            adj[x-1][nadj[x-1]++] = y-1, adj[y-1][nadj[y-1]++] = x-1;
        }
        for (i = 0; i < n; i++) val[i] = nadj[i];
        for (f = 1; f; ) {
            f = 0;
            for (i = 0; i < n; i++) if (val[i]>=0 && val[i]<k) {
                for (j = 0; j < nadj[i]; j++) val[adj[i][j]]--;
                val[i] = -1; f = 1;
            }
        }
        for (i = m = 0; i < n; i++) if (!disc[i] && val[i]>=0) { comp = 0; dfs(i); m>?=comp; }
        printf("%d\n", m);
    }
    
    return 0;
}
