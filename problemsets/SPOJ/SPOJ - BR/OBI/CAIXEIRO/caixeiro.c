#include <stdio.h>

int festa[610], path[610];
int adj[310][310], nadj[310];
char disc[310];
int c, f, max;


int LCS(int k) {
    int n = k<<1, dp[610][610];
    register int i, j;
    for (i = 1; i < k; i++) path[n-i] = path[i]; n--;
    for (i = 1; i <= n; i++) dp[i][0] = 0;
    for (j = 1; j <= f; j++) dp[0][j] = 0;
    for (i = 1; i <= n; i++) for (j = 1; j <= f; j++)
        if (path[i] == festa[j]) dp[i][j] = dp[i][j-1] + 1;
        else if (dp[i-1][j] >= dp[i][j-1]) dp[i][j] = dp[i-1][j];
        else dp[i][j] = dp[i][j-1];
    return dp[n][f];
}

void dfs(int v, int k) {
    register int i, x;
    path[k] = v; disc[v] = 1;
    if (v!=1 && nadj[v]==1) { x = LCS(k); if (x > max) max = x; return; }
    for (i = 0; i < nadj[v]; i++) {
        x = adj[v][i]; if (!disc[x]) dfs(x, k+1); 
    }
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    register int i, x, y, k = 1;
    while (1) {
        c = get_int(); f = get_int(); if (!c && !f) break;
        for (i = 1; i <= c; i++) nadj[i] = disc[i] = 0;
        for (i = 1; i < c; i++) { 
            x = get_int(); y = get_int(); adj[x][nadj[x]++] = y; adj[y][nadj[y]++] = x;
        }
        for (i = 1; i <= f; i++) festa[i] = get_int();
        if (c == 1) { printf("Teste %d\n1\n\n", k++); continue; }
        max = 1; dfs(1, 1); printf("Teste %d\n%d\n\n", k++, max);
    }
    return 0;
}

