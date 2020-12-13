/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>

using namespace std;

int M;

vector<int> adj[101010];

int prof[101010], ord[101010], nord;
bool ok;

void dfs_topsort(int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (prof[v]==-1) {
            prof[v] = prof[u]+1;
            dfs_topsort(v);
        }
        else if (prof[v] < prof[u]) ok = 0;
    }
    ord[--nord] = u;
}

void topsort() {
    for (int i = 0; i < M; i++) prof[i] = -1;
    nord = M;
    for (int i = 0; i < M; i++) if (prof[i]==-1) {
        prof[i] = 0;
        dfs_topsort(i);
    }
}


int main() {

    while (scanf("%d", &M) != EOF) {
        for (int i = 0; i < M; i++) adj[i].clear();
        for (int i = 1; i <= M; i++) {
            int d;
            scanf("%d", &d);
            for (int j = 0; j < d; j++) {
                int x;
                scanf("%d", &x);
                adj[i].push_back(x);
            }
        }
        ok = 1;
        topsort();
        if (!ok)  puts("inclassificavel");
        else {
            printf("%d", ord[0]);
            for (int i = 1; i < M; i++) printf(" %d", ord[i]);
            putchar('\n');
        }
    }

    return 0;
}
