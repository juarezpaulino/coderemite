/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> adj[1010101];
char in[1010101], id = 1;
int last, d;

void dfs(int u, int l) {
    if (l > d) last = u, d = l;
    in[u] = id;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (in[v]!=id) dfs(v, l+1);
    }
}

int main() {

    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    last = -1; d = 0; dfs(a, 0); id++;
    d = 0; dfs(last, 0);
    printf("%d\n", d);

    return 0;
}
