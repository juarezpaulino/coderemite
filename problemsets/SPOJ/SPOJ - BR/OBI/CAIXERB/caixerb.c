#include <stdio.h>
int adj[301][301], nadj[301], c, v;
char vis[301];
int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}
int dfs(int v, int last) {
    register int len, x, i;
    for (i = len = 0; i < nadj[v]; i++) if (adj[v][i]!=last) {
        x = dfs(adj[v][i], v); if (vis[adj[v][i]] || x) len += x+2;
    }
    return len;
}
int main() {
    register int i, x, y, k = 1;
    while (1) {
        c = get_int(); v = get_int(); if (!c && !v) break;
        for (i = 1; i <= c; i++) nadj[i] = vis[i] = 0;
        for (i = 1; i < c; i++) {
            x = get_int(); y = get_int(); adj[x][nadj[x]++] = y; adj[y][nadj[y]++] = x;
        }
        for (i = 0; i < v; i++) vis[get_int()] = 1;
        printf("Teste %d\n%d\n\n", k++, dfs(1, 0));
    }
    return 0;
}

