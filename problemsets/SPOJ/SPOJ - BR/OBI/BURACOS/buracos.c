#include <stdio.h>
short adj[3001][3001], nadj[3001], nivel[3001], nord, comp;
int n;
int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}
void dfs(int v) {
    int i, x, min = nivel[v] = nord++;
    for (i = 0; i < nadj[v]; i++) {
        x = adj[v][i]; if (nivel[x]==-1) dfs(x); if (nivel[x] < min) min = nivel[x];
    }
    if (min < nivel[v]) nivel[v] = min; else comp++;
    
}
int main() {
    int b, x, y;
    register int i, k = 1;
    while (1) {
        n = get_int(); b = get_int(); if (!n && !b) break;
        for (i = 1; i <= n; i++) nadj[i] = 0, nivel[i] = -1;
        for (i = 0; i < b; i++) {
            x = get_int(); y = get_int(); adj[x][nadj[x]++] = y;
        }
        nord = comp = 0; dfs(n); for (i = 1; i <= n; i++) if (nivel[i]==-1) break;
        if (i>n && comp == 1) printf("Teste %d\nS\n\n", k++);
        else printf("Teste %d\nN\n\n", k++);
    }
    return 0;
}

