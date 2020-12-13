/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int id = 1;
int ret;
int M, N;
int P[25], U[25], V[25];
vector<int> adj[25];

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return EOF;
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}

int dfs(int k) {
    if (k == M) return 1;
    V[k] = id;
    for (int i = 0; i < adj[k].size(); i++) if (V[adj[k][i]]!=id) {
        if (dfs(adj[k][i])) return 1;
    }
    return 0;
}

void go(int k) {
    int u = P[k];
    if (u == M) {
        printf("%d", P[0]);
        for (int i = 1; i <= k; i++) printf(" %d", P[i]);
        putchar('\n');
        ret++;
        return;
    }
    for (int i = 0; i < adj[u].size(); i++)
        if (!U[adj[u][i]]) {
            P[k+1] = adj[u][i];
            U[u] = 1; go(k+1); U[u] = 0;
        }
}


int main() {

    while ((M = get_int()) != EOF) {
        int a, b;
        for (int i = 1; i <= 23; i++) adj[i].clear();
        while (1) {
            a = get_int();
            b = get_int();
            if (!(a|b)) break;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printf("CASE %d:\n", id++);
        if (!dfs(1)) {
            printf("There are 0 routes from the firestation to streetcorner %d.\n", M);
            continue;
        }
        for (int i = 1; i <= 23; i++) if (adj[i].size()) sort(adj[i].begin(), adj[i].end());
        ret = 0; P[0] = 1; go(0);
        printf("There are %d routes from the firestation to streetcorner %d.\n", ret, M);
    }

    return 0;
}
