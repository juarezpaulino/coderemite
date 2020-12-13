/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>

int n, m;
int adj[50001][3], nadj[50001], ngate[50001];
char type[50001];

#define NORM 0
#define VIRA 1
#define TRAP 2

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

void dfs(int v, int p) {
    int i, y1, y2;
    if (nadj[v]==1 || type[v]==TRAP) return;
    if (nadj[v]==2) {
        if (adj[v][0]==p) y1 = adj[v][1]; else y1 = adj[v][0];
        dfs(y1, v); type[v] = type[y1], ngate[v] = ngate[y1];
    }
    else {
        y1 = adj[v][0]; y2 = adj[v][1];
        if (y1==p) y1 = adj[v][2]; else if (y2==p) y2 = adj[v][2];
        dfs(y1, v); dfs(y2, v);
        if (type[y1]>type[y2]) y1^=y2^=y1^=y2;
        if (type[y1]==NORM && type[y2]==NORM) type[v]=NORM;
        else if (type[y1]==NORM && type[y2]==VIRA) type[v]=VIRA, ngate[v]=ngate[y2];
        else if (type[y1]==NORM && type[y2]==TRAP) type[v]=VIRA, ngate[v]=ngate[y2];
        else if (type[y1]==VIRA && type[y2]==VIRA) type[v]=TRAP, ngate[v]=2+ngate[y1]+ngate[y2];
        else if (type[y1]==VIRA && type[y2]==TRAP) type[v]=TRAP, ngate[v]=1+ngate[y1]+ngate[y2];
        else type[v]=TRAP, ngate[v]=ngate[y1]+ngate[y2];
    }
}


int main() {

    int i, j;
    while (1) {
        n = get_int(); m = get_int(); if (!n && !m) break;
        for (i = 1; i <= n; i++) {
            nadj[i] = get_int(); for (j=0;j<nadj[i];j++) adj[i][j] = get_int();
            type[i] = NORM, ngate[i] = 0;
        }
        for (i = 0; i < m; i++) { j = get_int(); type[j] = TRAP; }
        dfs(adj[1][0], 1); j = ngate[adj[1][0]];
        if (type[adj[1][0]]!=TRAP) j++;
        printf("%d\n", j);
    }
    return 0;
}
